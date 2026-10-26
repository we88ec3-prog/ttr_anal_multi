
undefined4 FUN_005351e0(undefined4 *param_1,uint param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  uint in_ECX;
  uint uVar3;
  int iVar4;
  int *piVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puVar1 = param_1;
  local_8 = 0xffffffff;
  puStack_c = &LAB_009249de;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  piVar5 = param_1 + 0x17;
  FUN_005359f0(piVar5,&param_1,param_1[0x17],param_1[0x18]);
  if (in_ECX < 2) {
    uVar3 = 0;
  }
  else {
    uVar3 = (in_ECX - 2) / 0x1f;
  }
  if (uVar3 != 0) {
    puVar6 = (undefined4 *)(param_2 + 2);
    param_2 = uVar3;
    do {
      puVar7 = (undefined4 *)puVar1[0x18];
      param_1 = puVar6;
      if ((puVar6 < puVar7) && (puVar8 = (undefined4 *)*piVar5, puVar8 <= puVar6)) {
        if (puVar7 == (undefined4 *)puVar1[0x19]) {
          FUN_00535a40(uVar2);
        }
        puVar7 = (undefined4 *)puVar1[0x18];
        puVar6 = (undefined4 *)((((int)puVar6 - (int)puVar8) / 0x1f) * 0x1f + *piVar5);
        puVar8 = param_1;
      }
      else {
        if (puVar7 == (undefined4 *)puVar1[0x19]) {
          FUN_00535a40(uVar2);
        }
        puVar7 = (undefined4 *)puVar1[0x18];
        puVar8 = puVar6;
      }
      if (puVar7 != (undefined4 *)0x0) {
        for (iVar4 = 7; iVar4 != 0; iVar4 = iVar4 + -1) {
          *puVar7 = *puVar6;
          puVar6 = puVar6 + 1;
          puVar7 = puVar7 + 1;
        }
        *(undefined2 *)puVar7 = *(undefined2 *)puVar6;
        *(undefined1 *)((int)puVar7 + 2) = *(undefined1 *)((int)puVar6 + 2);
        puVar8 = param_1;
      }
      puVar1[0x18] = puVar1[0x18] + 0x1f;
      puVar6 = (undefined4 *)((int)puVar8 + 0x1f);
      param_2 = param_2 - 1;
      param_1 = puVar6;
    } while (param_2 != 0);
  }
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_8 = 0;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_8 = 0xffffffff;
  }
  FUN_0058aad0(0xf4285);
  ExceptionList = local_10;
  return 0;
}

