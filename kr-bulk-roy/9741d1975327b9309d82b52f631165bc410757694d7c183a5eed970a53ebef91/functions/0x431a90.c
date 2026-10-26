
void FUN_00431a90(char param_1)

{
  uint in_EAX;
  undefined4 uVar1;
  int in_ECX;
  uint uVar2;
  char *local_20;
  undefined **local_1c [3];
  undefined4 local_10;
  undefined4 local_c;
  
  *(uint *)(in_ECX + 0xc) = in_EAX & 0x17;
  uVar2 = *(uint *)(in_ECX + 0x10) & in_EAX & 0x17;
  if (uVar2 == 0) {
    return;
  }
  if (param_1 != '\0') {
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(0,0);
  }
  if ((uVar2 & 4) != 0) {
    uVar1 = FUN_0087e14b();
    local_20 = "ios_base::badbit set";
    std::exception::exception((exception *)local_1c,&local_20);
    local_10 = 1;
    local_1c[0] = std::ios_base::failure::vftable;
    local_c = uVar1;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_1c,&DAT_00c8583c);
  }
  if ((uVar2 & 2) != 0) {
    uVar1 = FUN_0087e14b();
    local_20 = "ios_base::failbit set";
    std::exception::exception((exception *)local_1c,&local_20);
    local_10 = 1;
    local_1c[0] = std::ios_base::failure::vftable;
    local_c = uVar1;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_1c,&DAT_00c8583c);
  }
  uVar1 = FUN_0087e14b();
  local_20 = "ios_base::eofbit set";
  std::exception::exception((exception *)local_1c,&local_20);
  local_10 = 1;
  local_1c[0] = std::ios_base::failure::vftable;
  local_c = uVar1;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_1c,&DAT_00c8583c);
}

