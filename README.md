# Keystone Fork

**Work done on this repo:**
- Upgrade cmake version and fix warnings
- Re-enabled all LLVM error messages (`Error()`)
- Adds `ks_set_error_message_handler` to handle error messages
- Fixes several RISC-V bugs (missing address increment, typos, fix for `la`)
- Implement `ks_set_instruction_stream_handler`
- Implement `ksApplyOptions` method for AsmParsers and `KS_MODE_RISCVC`
