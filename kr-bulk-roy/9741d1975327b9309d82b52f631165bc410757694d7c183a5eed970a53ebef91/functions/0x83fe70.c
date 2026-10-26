
undefined4 FUN_0083fe70(uint param_1)

{
  int in_EAX;
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined1 local_c [4];
  uint local_8;
  
  if (param_1 != 0) {
    uVar3 = param_1 & 0xffff;
    if (((uVar3 < (uint)((*(int *)(in_EAX + 0x14) - *(int *)(in_EAX + 0x10)) / 0x34)) &&
        (*(uint *)(*(int *)(in_EAX + 0x20) + uVar3 * 4) == param_1 >> 0x10)) &&
       (uVar3 * 0x34 + *(int *)(in_EAX + 0x10) != 0)) {
      local_8 = 0;
      iVar1 = FUN_0083fd10(&param_1,&local_8);
      if (iVar1 != 0) {
        puVar2 = (undefined4 *)FUN_007df190(&local_8);
        FUN_007c2e30(in_EAX,local_c,*puVar2);
        local_8 = param_1 & 0xffff;
        *(undefined4 *)(*(int *)(in_EAX + 0x20) + local_8 * 4) = 0;
        FUN_006de9c0();
        return 1;
      }
    }
  }
  return 0;
}

