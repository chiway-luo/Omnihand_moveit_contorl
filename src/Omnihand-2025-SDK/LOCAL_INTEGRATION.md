# Local integration policy

This workspace is based on AGILINK OmniHand SDK `v1.1.8` at commit
`026740d9fdd8ba32b0605fa702a992b322076f1b`.

The public ROS 2 workspace mirrors the upstream documentation and Linux SDK
payloads needed for Ubuntu 22.04. The upstream Windows bundle is intentionally
excluded because it is outside the deployment target and did not pass the
repository credential scan. Obtain Windows packages directly from the upstream
project when they are required.

The SDK tree is retained only for provenance and API documentation. It carries
`COLCON_IGNORE` and must not be compiled by this workspace. The ROS node uses
the versioned Linux x86_64 headers and prebuilt libraries vendored inside
`src/hand_test/omnihand_node`.
