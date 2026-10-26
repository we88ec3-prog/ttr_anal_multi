
undefined4 FUN_005ad880(uint param_1)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined4 uVar3;
  undefined *puVar4;
  
  if (param_1 < 0x2916) {
    if (param_1 == 0x2915) {
      FUN_0064e6c0(*(char *)(*(int *)(in_ECX + 0x21c) + 0x104) == '\0');
      return 1;
    }
    if (param_1 == 0x2774) {
      iVar1 = *(int *)(*(int *)(in_ECX + 0x224) + 0x11c);
      if ((iVar1 != 0) && ((*(uint *)(iVar1 + 0x28) >> 8 & 1) != 0)) {
        uVar3 = 0;
        puVar4 = PTR_DAT_00f86200;
        uVar2 = FUN_0040f8c0(0,PTR_DAT_00f86200);
        FUN_004d5ae0(uVar2,uVar3,puVar4);
        return 1;
      }
    }
    else if (param_1 == 0x2775) {
      iVar1 = *(int *)(*(int *)(in_ECX + 0x224) + 0x120);
      if ((iVar1 != 0) && ((*(uint *)(iVar1 + 0x28) >> 8 & 1) != 0)) {
        uVar3 = 0;
        puVar4 = PTR_DAT_00f86204;
        uVar2 = FUN_0040f8c0(0,PTR_DAT_00f86204);
        FUN_004d5ae0(uVar2,uVar3,puVar4);
        return 1;
      }
    }
    else {
      if (param_1 != 0x2776) goto LAB_005ad99e;
      iVar1 = *(int *)(*(int *)(in_ECX + 0x224) + 0x124);
      if ((iVar1 != 0) && ((*(uint *)(iVar1 + 0x28) >> 8 & 1) != 0)) {
        uVar3 = 0;
        puVar4 = PTR_DAT_00f86208;
        uVar2 = FUN_0040f8c0(0,PTR_DAT_00f86208);
        FUN_004d5ae0(uVar2,uVar3,puVar4);
        return 1;
      }
    }
  }
  else {
    if (param_1 != 0x2af9) {
      if (param_1 == 0x2afb) {
        iVar1 = **(int **)(in_ECX + 0x248);
        if (((uint)(*(int **)(in_ECX + 0x248))[10] >> 8 & 1) == 0) {
          (**(code **)(iVar1 + 0xd0))();
          return 1;
        }
        (**(code **)(iVar1 + 0xd4))();
        return 1;
      }
LAB_005ad99e:
      uVar2 = FUN_0059cc50(param_1);
      return uVar2;
    }
    FUN_0059a230();
  }
  return 1;
}

