
void FUN_00733180(int *param_1,undefined4 *param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  int in_ECX;
  int *unaff_EBX;
  
  if (*(int *)(*(int *)(*param_1 + 4) + 0xc + (int)param_1) == 0) {
    while ((iVar2 = FUN_00733b00(param_1), (char)unaff_EBX[0x11] != '\0' || (iVar2 != 0x3c))) {
      if (iVar2 < 1) {
        while (iVar2 = (**(code **)(*unaff_EBX + 0x10))(), iVar2 == 0) {
          unaff_EBX = (int *)unaff_EBX[4];
          if (unaff_EBX == (int *)0x0) {
            return;
          }
        }
        iVar2 = (**(code **)(*unaff_EBX + 0x10))();
        if (iVar2 == 0) {
          return;
        }
        FUN_00732010(0xe,0,0,0);
        return;
      }
      FUN_00429630(1,iVar2);
      FUN_00733980(param_1);
      if (((*(char *)(in_ECX + 0x44) != '\0') && (iVar2 == 0x3e)) && (uVar1 = param_2[4], 2 < uVar1)
         ) {
        puVar3 = param_2;
        if (0xf < (uint)param_2[5]) {
          puVar3 = (undefined4 *)*param_2;
        }
        if (*(char *)((int)puVar3 + (uVar1 - 2)) == ']') {
          puVar3 = param_2;
          if (0xf < (uint)param_2[5]) {
            puVar3 = (undefined4 *)*param_2;
          }
          if (*(char *)((int)puVar3 + (uVar1 - 3)) == ']') {
            return;
          }
        }
      }
      if (*(int *)(*(int *)(*param_1 + 4) + 0xc + (int)param_1) != 0) {
        return;
      }
    }
  }
  return;
}

