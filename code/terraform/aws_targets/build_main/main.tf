// main.tf

// TODO:
//  - Get output public IP addressess
//  - Figure out how to create one user name

provider "aws" {
    region = "us-east-2"
}

module "targets" {
    source = "../modules/targets"

    project_name = "python_testing"
    instance_type = "t2.micro"
    key_name   = "aws_key"
    public_key = "really long string"

}
