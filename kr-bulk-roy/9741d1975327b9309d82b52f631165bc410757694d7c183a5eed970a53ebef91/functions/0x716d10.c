
uint FUN_00716d10(int *param_1)

{
  char cVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int *piVar6;
  int iVar7;
  
  piVar6 = param_1 + 1;
  cVar1 = (**(code **)(param_1[1] + 4))();
  cVar2 = (**(code **)(*piVar6 + 4))();
  if ((cVar1 != '\x1f') || (cVar2 != -0x75)) {
    return 0xfffffffb;
  }
  cVar1 = (**(code **)(*piVar6 + 4))();
  uVar3 = (**(code **)(*piVar6 + 4))();
  if ((cVar1 != '\b') || ((uVar3 & 0xe0) != 0)) {
    return 0xfffffffd;
  }
  iVar7 = 6;
  do {
    (**(code **)(*piVar6 + 4))();
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  if ((uVar3 & 4) != 0) {
    uVar4 = (**(code **)(*piVar6 + 4))();
    uVar5 = (**(code **)(*piVar6 + 4))();
    iVar7 = (uVar4 & 0xff) + (uVar5 & 0xff) * 0x100;
    do {
      if (iVar7 == 0) break;
      cVar1 = (**(code **)(*piVar6 + 4))();
      iVar7 = iVar7 + -1;
    } while (cVar1 != '\0');
  }
  if ((uVar3 & 8) != 0) {
    do {
      cVar1 = (**(code **)(*piVar6 + 4))();
    } while (cVar1 != '\0');
  }
  if ((uVar3 & 0x10) != 0) {
    do {
      cVar1 = (**(code **)(*piVar6 + 4))();
    } while (cVar1 != '\0');
  }
  if ((uVar3 & 2) != 0) {
    iVar7 = 2;
    do {
      (**(code **)(*piVar6 + 4))();
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
  }
  cVar1 = (**(code **)(*param_1 + 4))();
  return -(uint)(cVar1 != '\0') & 0xfffffffd;
}

