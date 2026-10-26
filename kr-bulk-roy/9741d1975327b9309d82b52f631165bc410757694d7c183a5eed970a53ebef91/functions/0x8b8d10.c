
uint FUN_008b8d10(uint param_1,uint param_2,uint *param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  iVar2 = param_1;
  uVar3 = 0;
  uVar4 = 0;
  if (((param_1 != 0) && (iVar1 = *(int *)(param_1 + 0x5c), iVar1 != 0)) &&
     (*(int *)(param_1 + 0x10) != 0)) {
    param_1 = param_2;
    do {
      uVar4 = (**(code **)(*(int *)(iVar1 + 0xc) + 0x10))(iVar1,&param_1);
    } while (*(uint *)(iVar2 + 0x10) <= uVar4);
    uVar3 = -(uint)(uVar4 != 0) & param_1;
  }
  if (param_3 != (uint *)0x0) {
    *param_3 = uVar4;
  }
  return uVar3;
}

