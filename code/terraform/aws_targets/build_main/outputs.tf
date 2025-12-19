// outputs.tf


output "ubuntu_public_ip" {
    description = "IP address of the instance"
    value   = module.targets.ubuntu_public_ip
}

output "aws_linux_public_ip" {
    description = "IP address of the instance"
    value   = module.targets.aws_linux_public_ip
}

