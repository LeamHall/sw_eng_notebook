// main.tf

resource "aws_security_group" "instance" {
  name  = var.project_name

  egress = [{
    cidr_blocks   = [ "0.0.0.0/0" ]
    ipv6_cidr_blocks = []
    prefix_list_ids   = []
    description   = ""
    from_port     = 0
    to_port       = 0
    protocol       = "-1"
    security_groups = []
    self          = false
    } ] 

  ingress {
    from_port   = 22
    to_port     = 22
    protocol    ="tcp"
    cidr_blocks = ["0.0.0.0/0"]
  }
}

resource "aws_key_pair" "deployer" {
  key_name   = var.key_name
  public_key = var.public_key
}

resource "aws_instance" "ubuntu_target" {
  ami           = "ami-0c55b159cbfafe1f0"
  instance_type = var.instance_type
  key_name      = var.key_name

  vpc_security_group_ids = [aws_security_group.instance.id]

  tags = {
    Name = "ubuntu_target"
  }

  connection {
    type    = "ssh"
    host    = self.public_ip
    user    = "leam"
    private_key = file("/home/leam/.ssh/aws_key")
    timeout = "4m"
  }
}

resource "aws_instance" "aws_linux_target" {
  ami           = "ami-0beaa649c482330f7"
  instance_type = var.instance_type
  key_name      = var.key_name

  vpc_security_group_ids = [aws_security_group.instance.id]

  tags = {
    Name = "aws_linux_target"
  }

  connection {
    type    = "ssh"
    host    = self.public_ip
    user    = "leam"
    private_key = file("/home/leam/.ssh/aws_key")
    timeout = "4m"
  }
}

