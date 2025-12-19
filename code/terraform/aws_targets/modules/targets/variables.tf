// variables.tf
//variable "ami_key_pair_name" {}

variable "project_name" {
    description = "The project name"
    type        = string
}

variable "instance_type" {
    description = "The type of EC2 instance"
    type        = string
}


