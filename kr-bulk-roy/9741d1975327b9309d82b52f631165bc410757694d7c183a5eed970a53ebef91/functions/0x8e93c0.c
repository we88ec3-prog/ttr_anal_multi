
void FUN_008e93c0(int param_1,int param_2,uint param_3,byte param_4,undefined4 *param_5)

{
  int iVar1;
  uint uVar2;
  undefined1 local_5e4 [40];
  undefined4 local_5bc;
  undefined1 local_5a0;
  undefined1 local_59e;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_14;
  undefined4 local_10;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  if ((param_4 & 0x10) == 0) {
    iVar1 = (*(code *)**(undefined4 **)(*(int *)(param_1 + 0x1e8) + 0xc))
                      (local_5e4,param_1,0,0,*(undefined4 *)(param_1 + 0x1a4),
                       *(undefined4 *)(param_1 + 0x210),0,0,FUN_008e9260);
    if (iVar1 == 0) {
      local_8c = *(undefined4 *)(param_1 + 0x198);
      local_88 = *(undefined4 *)(param_1 + 0x19c);
      local_5a0 = 0;
      local_90 = *(undefined4 *)(param_1 + 0x194);
      local_14 = *(undefined4 *)(param_1 + 0x220);
      local_10 = *(undefined4 *)(param_1 + 0x21c);
      uVar2 = 0;
      local_59e = 1;
      if (param_3 != 0) {
        do {
          iVar1 = FUN_008e9260(local_5e4,uVar2 + param_2);
          if (iVar1 == 0) {
            iVar1 = FUN_008b7c80(local_5bc);
            param_5[uVar2] = iVar1 >> 0x10;
          }
          else {
            param_5[uVar2] = 0;
          }
          uVar2 = uVar2 + 1;
        } while (uVar2 < param_3);
      }
    }
  }
  else if (param_3 != 0) {
    for (; param_3 != 0; param_3 = param_3 - 1) {
      *param_5 = 0;
      param_5 = param_5 + 1;
    }
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

