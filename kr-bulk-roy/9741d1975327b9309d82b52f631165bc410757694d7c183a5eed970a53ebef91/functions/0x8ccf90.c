
void FUN_008ccf90(int param_1,undefined4 param_2,uint *param_3)

{
  uint uVar1;
  int in_EAX;
  int iVar2;
  uint uVar3;
  uint *unaff_EDI;
  int local_c;
  int *local_8;
  
  uVar3 = 0;
  local_c = 0;
  if (in_EAX < 0) {
    local_c = 1;
    if (in_EAX == -0x15) {
      param_1 = param_1 + -0x15;
      local_c = 3;
    }
    in_EAX = 0;
  }
  if (param_3 != (uint *)0x0) {
    *param_3 = 0xffffffff;
  }
  uVar1 = *unaff_EDI;
  local_8 = (int *)unaff_EDI[2];
  if (uVar1 != 0) {
    do {
      if ((*local_8 == param_1) && (local_8[1] == in_EAX)) {
        if (uVar3 < uVar1) goto LAB_008cd01c;
        break;
      }
      uVar3 = uVar3 + 1;
      local_8 = local_8 + 3;
    } while (uVar3 < uVar1);
  }
  iVar2 = FUN_008cc9f0(param_2,&local_8);
  if (iVar2 == 0) {
    *local_8 = param_1;
    local_8[1] = in_EAX;
    local_8[2] = local_c;
LAB_008cd01c:
    iVar2 = FUN_008ccc20(param_2);
    if (((iVar2 == 0) && (iVar2 = FUN_008ccb00(), iVar2 == 0)) && (param_3 != (uint *)0x0)) {
      *param_3 = uVar3;
    }
  }
  return;
}

