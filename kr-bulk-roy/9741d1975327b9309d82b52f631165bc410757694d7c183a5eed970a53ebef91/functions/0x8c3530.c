
undefined4
FUN_008c3530(int param_1,int param_2,uint param_3,undefined2 *param_4,undefined2 *param_5)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined2 uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  
  uVar3 = param_3;
  uVar2 = *(undefined4 *)(param_1 + 0x68);
  if ((char)param_2 == '\0') {
    iVar7 = *(int *)(param_1 + 0x310);
    iVar8 = param_1 + 0xd8;
    iVar5 = *(int *)(param_1 + 0x2ac);
  }
  else {
    iVar7 = *(int *)(param_1 + 0x314);
    iVar8 = param_1 + 0x128;
    iVar5 = *(int *)(param_1 + 0x2b4);
  }
  uVar1 = iVar5 + iVar7;
  uVar6 = (uint)*(ushort *)(iVar8 + 0x22);
  if (*(ushort *)(iVar8 + 0x22) != 0) {
    if (param_3 < uVar6) {
      iVar7 = iVar7 + param_3 * 4;
      if ((iVar7 + 4U <= uVar1) && (param_2 = FUN_008b97e0(uVar2,iVar7), param_2 == 0)) {
        uVar4 = FUN_008b9ab0(uVar2,&param_2);
        *param_5 = uVar4;
        if (param_2 == 0) {
          uVar4 = FUN_008b9ab0(uVar2,&param_2);
          *param_4 = uVar4;
          if (param_2 == 0) {
            return 0;
          }
        }
      }
    }
    else {
      iVar8 = iVar7 + -4 + uVar6 * 4;
      if ((iVar8 + 4U <= uVar1) && (param_2 = FUN_008b97e0(uVar2,iVar8), param_2 == 0)) {
        uVar4 = FUN_008b9ab0(uVar2,&param_2);
        *param_5 = uVar4;
        if (param_2 == 0) {
          iVar8 = iVar8 + 4 + (uVar3 - uVar6) * 2;
          if (uVar1 < iVar8 + 2U) {
            *param_4 = 0;
            return 0;
          }
          param_2 = FUN_008b97e0(uVar2,iVar8);
          if (param_2 != 0) {
            return 0;
          }
          uVar4 = FUN_008b9ab0(uVar2,&param_2);
          *param_4 = uVar4;
          return 0;
        }
      }
    }
  }
  *param_4 = 0;
  *param_5 = 0;
  return 0;
}

