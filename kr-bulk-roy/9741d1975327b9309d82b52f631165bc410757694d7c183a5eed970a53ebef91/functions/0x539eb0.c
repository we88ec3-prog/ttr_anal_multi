
undefined4 FUN_00539eb0(uint param_1,ushort *param_2)

{
  int *piVar1;
  uint uVar2;
  int in_ECX;
  int iVar3;
  ushort *puVar4;
  ushort *puVar5;
  ushort *puVar6;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  iVar3 = param_1;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092484e;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(uint *)(in_ECX + 0x5eac) = (uint)*(byte *)(param_1 + 2);
  piVar1 = (int *)(in_ECX + 0x5eb8);
  *(uint *)(in_ECX + 0x5eb0) = (uint)*(byte *)(param_1 + 3);
  FUN_0053bdb0(piVar1,&param_1,*piVar1,*(undefined4 *)(in_ECX + 0x5ebc));
  *(undefined4 *)(in_ECX + 0x5eb4) = 0;
  if (param_2 < (ushort *)0x6) {
    param_1 = 0;
  }
  else {
    param_1 = (uint)(param_2 + -3) / 0x36;
  }
  FUN_0053bcc0(param_1);
  if (param_1 != 0) {
    puVar5 = (ushort *)(iVar3 + 6);
    do {
      param_2 = puVar5;
      if ((puVar5 < *(ushort **)(in_ECX + 0x5ebc)) && (puVar4 = (ushort *)*piVar1, puVar4 <= puVar5)
         ) {
        if (*(int *)(in_ECX + 0x5ebc) == *(int *)(in_ECX + 0x5ec0)) {
          FUN_0053be00(uVar2);
        }
        puVar6 = *(ushort **)(in_ECX + 0x5ebc);
        puVar4 = (ushort *)((((int)puVar5 - (int)puVar4) / 0x36) * 0x36 + *piVar1);
      }
      else {
        if (*(ushort **)(in_ECX + 0x5ebc) == *(ushort **)(in_ECX + 0x5ec0)) {
          FUN_0053be00(uVar2);
        }
        puVar6 = *(ushort **)(in_ECX + 0x5ebc);
        puVar4 = puVar5;
      }
      if (puVar6 != (ushort *)0x0) {
        for (iVar3 = 0xd; iVar3 != 0; iVar3 = iVar3 + -1) {
          *(undefined4 *)puVar6 = *(undefined4 *)puVar4;
          puVar4 = puVar4 + 2;
          puVar6 = puVar6 + 2;
        }
        *puVar6 = *puVar4;
        puVar5 = param_2;
      }
      *(int *)(in_ECX + 0x5ebc) = *(int *)(in_ECX + 0x5ebc) + 0x36;
      if ((*(int *)(in_ECX + 0x5ed8) != 0) &&
         (*(uint *)(*(int *)(in_ECX + 0x5ed8) + 0x24) == (uint)*puVar5)) {
        *(int *)(in_ECX + 0x5eb4) = *(int *)(in_ECX + 0x5ebc) + -0x36;
      }
      puVar5 = puVar5 + 0x1b;
      param_1 = param_1 - 1;
      param_2 = puVar5;
    } while (param_1 != 0);
  }
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_8 = 0;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_8 = 0xffffffff;
  }
  FUN_0058aad0(0xf42a0);
  ExceptionList = local_10;
  return 0;
}

