
undefined4 FUN_00808fa0(undefined4 param_1,int param_2)

{
  int *in_EAX;
  int iVar1;
  char *pcVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  undefined4 *puVar7;
  bool bVar8;
  
  (**(code **)(*in_EAX + 0x14))();
  iVar1 = FUN_007300a0("isandop");
  if (iVar1 != 0) {
    pcVar2 = (char *)(iVar1 + 0x30);
    if (0xf < *(uint *)(iVar1 + 0x44)) {
      pcVar2 = *(char **)pcVar2;
    }
    if (pcVar2 != (char *)0x0) {
      iVar1 = __stricmp(pcVar2,"true");
      bVar8 = iVar1 == 0;
      goto LAB_00808fe9;
    }
  }
  bVar8 = true;
LAB_00808fe9:
  *(uint *)(param_2 + 0x20) = (uint)bVar8;
  piVar3 = (int *)FUN_0072e2e0(&DAT_00c517c8);
joined_r0x00809002:
  do {
    if (piVar3 == (int *)0x0) {
      return 1;
    }
    iVar4 = (**(code **)(*piVar3 + 0x14))();
    for (iVar1 = *(int *)(iVar4 + 0x94); iVar1 != iVar4 + 0x44; iVar1 = *(int *)(iVar1 + 0x50)) {
      pcVar2 = (char *)(iVar1 + 0x14);
      if (0xf < *(uint *)(iVar1 + 0x28)) {
        pcVar2 = *(char **)pcVar2;
      }
      iVar5 = __stricmp(pcVar2,"name");
      if (iVar5 == 0) {
        if (iVar1 == 0) break;
        puVar7 = (undefined4 *)(iVar1 + 0x30);
        if (0xf < *(uint *)(iVar1 + 0x44)) {
          puVar7 = (undefined4 *)*puVar7;
        }
        if (puVar7 == (undefined4 *)0x0) break;
        piVar6 = (int *)FUN_00809490();
        if (piVar6 != (int *)0x0) {
          iVar1 = (**(code **)(*piVar6 + 0xc))(piVar3);
          if (iVar1 != 0) {
            FUN_007bb350();
            break;
          }
          (**(code **)*piVar6)(1);
        }
        return 0;
      }
    }
    for (piVar3 = (int *)piVar3[0x10]; piVar3 != (int *)0x0; piVar3 = (int *)piVar3[0x10]) {
      piVar6 = piVar3 + 8;
      if (0xf < (uint)piVar3[0xd]) {
        piVar6 = (int *)*piVar6;
      }
      iVar1 = __stricmp((char *)piVar6,"CMD");
      if (iVar1 == 0) goto joined_r0x00809002;
    }
    piVar3 = (int *)0x0;
  } while( true );
}

