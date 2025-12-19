// outputs.tf


output "ubuntu_public_ip" {
    description = "IP address of the instance"
    value   = aws_instance.ubuntu_target.public_ip
}

output "aws_linux_public_ip" {
    description = "IP address of the instance"
    value   = aws_instance.aws_linux_target.public_ip
}

