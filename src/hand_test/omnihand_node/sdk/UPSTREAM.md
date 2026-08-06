# Vendored AGILINK OmniHand SDK

- Upstream: https://github.com/AgibotTech/agillink_omnihand_sdk
- Version: `v1.1.8`
- Commit: `026740d9fdd8ba32b0605fa702a992b322076f1b`
- Platform: Linux x86_64
- Source paths: `linux/x64/cpp/include` and `linux/x64/cpp/lib`

The official headers are copied into `omnihand_node/include`, and the complete
prebuilt runtime is copied into `omnihand_node/lib`. The SDK itself is never
compiled. Refresh both upstream source paths together so the headers,
ABI-versioned library, and vendor runtime closure remain from the same
immutable release.

The upstream repository states Mulan PSL v2 in its README and source headers,
but the v1.1.8 tree does not contain a standalone LICENSE or NOTICE file.
Confirm redistribution terms with the upstream project before distributing a
binary package outside this course workspace.
