Terraform AWS Target Instances
===============================

This Terraform configuration demonstrates AWS infrastructure as code using a modular approach. It creates EC2 instances with security groups and SSH key pairs.


Directory Structure
-------------------

aws_targets/
├── build_main/           # Root configuration
│   ├── main.tf           # Provider and module invocation
│   ├── variables.tf      # Root variables (currently empty)
│   └── outputs.tf        # Exposes module outputs
└── modules/
    └── targets/          # Reusable infrastructure module
        ├── main.tf       # Module resources (security group, key pair, instances)
        ├── variables.tf  # Module input parameters
        ├── outputs.tf    # Module output values
        └── main.tf.share # Alternative standalone example


Files Overview
--------------

build_main/main.tf:
  - Configures AWS provider (region: us-east-2)
  - Invokes the targets module with parameters:
    * project_name: "python_testing"
    * instance_type: "t2.micro"
    * key_name: "aws_key"
    * public_key: Your SSH public key string

modules/targets/main.tf:
  - Creates AWS security group (allows SSH on port 22 from anywhere)
  - Creates AWS key pair for SSH access
  - Launches two EC2 instances:
    * ubuntu_target (Ubuntu AMI)
    * aws_linux_target (Amazon Linux AMI)
  - Configures SSH connection settings

modules/targets/main.tf.share:
  - Alternative standalone example (no modules)
  - Includes simple HTTP server via user_data
  - Good for learning basic Terraform patterns


Prerequisites
-------------

1. AWS Account with credentials configured
2. Terraform installed (v1.0+)
3. AWS CLI configured with access keys
4. SSH key pair generated locally


Configuration Steps
-------------------

1. Update build_main/main.tf:
   - Replace "really long string" with your SSH public key
   - Optionally change project_name and instance_type

2. Update modules/targets/main.tf:
   - Update AMI IDs if using different regions
   - Change private_key path in connection blocks
   - Adjust SSH user if needed


Usage
-----

Initialize Terraform (downloads AWS provider):
  cd build_main/
  terraform init

Preview infrastructure changes:
  terraform plan

Create infrastructure:
  terraform apply

View outputs (public IPs):
  terraform output

Destroy infrastructure:
  terraform destroy


Outputs
-------

After successful apply, you'll get:
- ubuntu_public_ip: Public IP of Ubuntu instance
- aws_linux_public_ip: Public IP of Amazon Linux instance


SSH Access
----------

Connect to instances using:
  ssh -i ~/.ssh/aws_key ubuntu@<ubuntu_public_ip>
  ssh -i ~/.ssh/aws_key ec2-user@<aws_linux_public_ip>


Security Considerations
-----------------------

IMPORTANT: This configuration allows SSH from anywhere (0.0.0.0/0).
For production use:
- Restrict cidr_blocks to your IP address
- Use more restrictive security group rules
- Implement proper key management
- Enable encryption at rest
- Use private subnets where appropriate


Module Pattern Benefits
------------------------

The module pattern (build_main/ + modules/) provides:
- Reusability: Use the targets module in multiple projects
- Separation: Configuration separated from resource definitions
- Maintainability: Update module logic without changing root config
- Testing: Test modules independently


Learning Path
-------------

1. Start with modules/targets/main.tf.share (standalone example)
2. Understand basic resources: security group, key pair, instance
3. Progress to the modular approach (build_main + modules)
4. Customize for your specific use cases


See Also
--------

- sections/aws__terraform.txt - Terraform module pattern documentation
- Terraform AWS Provider Docs: https://registry.terraform.io/providers/hashicorp/aws/latest/docs
