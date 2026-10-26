
void FUN_005dd050(undefined4 param_1,uint param_2)

{
  int *piVar1;
  undefined2 uVar2;
  int iVar3;
  int unaff_EDI;
  undefined4 local_c;
  uint local_8;
  
  if (*(char *)(unaff_EDI + 0x2a0) == '\0') {
    if (*(int *)(unaff_EDI + 600) != 0) {
      iVar3 = FUN_0051c080();
      if (iVar3 == 0) goto LAB_005dd060;
    }
    iVar3 = *(int *)(unaff_EDI + 600);
    if (((iVar3 != 0) && (*(int *)(iVar3 + 0x68) != 0)) && (*(int *)(iVar3 + 0x68) != 0)) {
      uVar2 = *(undefined2 *)(*(int *)(iVar3 + 0x68) + 8);
      FUN_00404ba0();
      iVar3 = FUN_004d9c50(uVar2);
      if ((iVar3 == 0) || (*(int *)(iVar3 + 0xc) == 0)) goto LAB_005dd060;
    }
    local_c = param_1;
    local_8 = param_2;
    iVar3 = FUN_00409560();
    FUN_004dd400(iVar3,&param_2,&local_c);
    if ((param_2 == *(uint *)(iVar3 + 4)) ||
       ((piVar1 = (int *)(param_2 + 0x18), *piVar1 == 0 ||
        (param_2 = CONCAT31(param_2._1_3_,1), *(int *)(*piVar1 + 0x24) == 0)))) {
      param_2 = param_2 & 0xffffff00;
    }
  }
  else {
LAB_005dd060:
    param_2 = CONCAT31(param_2._1_3_,1);
  }
  (**(code **)(**(int **)(unaff_EDI + 0x2a8) + 0x94))(param_2);
  return;
}

