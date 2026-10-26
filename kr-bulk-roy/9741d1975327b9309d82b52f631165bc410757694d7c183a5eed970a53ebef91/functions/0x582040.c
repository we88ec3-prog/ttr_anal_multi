
void FUN_00582040(void)

{
  int *piVar1;
  float fVar2;
  int *in_EAX;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_8;
  
  if (in_EAX[0xb] != 0) {
    iVar3 = *in_EAX;
    iVar4 = *(int *)(iVar3 + 0x14) - *(int *)(iVar3 + 0x10);
    iVar5 = iVar4 >> 0x1f;
    if (iVar4 / 0x24 + iVar5 == iVar5) {
      iVar5 = 0;
    }
    else {
      iVar5 = *(int *)(*(int *)(iVar3 + 0x10) + 0x10);
    }
    if ((uint)((*(int *)(iVar3 + 0x14) - *(int *)(iVar3 + 0x10)) / 0x24) < 3) {
      iVar4 = 0;
    }
    else {
      iVar4 = *(int *)(*(int *)(iVar3 + 0x10) + 0x58);
    }
    if ((uint)((*(int *)(iVar3 + 0x14) - *(int *)(iVar3 + 0x10)) / 0x24) < 2) {
      local_8 = 0;
    }
    else {
      local_8 = *(int *)(*(int *)(iVar3 + 0x10) + 0x34);
    }
    fVar2 = (float)((in_EAX[9] - iVar4) - iVar5) / (float)local_8;
    FUN_00739180(0,0,0,0,0,0x3f800000,0x3f800000,0x3f800000,0x3f800000);
    piVar1 = (int *)*in_EAX;
    iVar3 = 0;
    if ((piVar1[5] - piVar1[4]) / 0x24 != 0) {
      iVar3 = *(int *)(piVar1[4] + 0x10);
    }
    (**(code **)(*piVar1 + 0xc))
              ((float)iVar3,0,0,fVar2,0x3f800000,0,DAT_00f7fc34,DAT_00f7fc38,DAT_00f7fc3c,
               DAT_00f7fc40,1,0,0x3f800000,0x3f800000,0x3f800000,0x3f800000);
    FUN_00739180((float)in_EAX[9],0,0,2,0,0x3f800000,0x3f800000,0x3f800000,0x3f800000);
    FUN_00739180(0,(float)in_EAX[10],0,3,0,0x3f800000,0x3f800000,0x3f800000,0x3f800000);
    piVar1 = (int *)*in_EAX;
    if ((uint)((piVar1[5] - piVar1[4]) / 0x24) < 4) {
      iVar3 = 0;
    }
    else {
      iVar3 = *(int *)(piVar1[4] + 0x7c);
    }
    (**(code **)(*piVar1 + 0xc))
              ((float)iVar3,(float)in_EAX[10],0,fVar2,0x3f800000,0,DAT_00f7fc34,DAT_00f7fc38,
               DAT_00f7fc3c,DAT_00f7fc40,4,0,0x3f800000,0x3f800000,0x3f800000,0x3f800000);
    FUN_00739180((float)in_EAX[9],(float)in_EAX[10],0,5,0,0x3f800000,0x3f800000,0x3f800000,
                 0x3f800000);
    if ((in_EAX[0xc] != 0) && (in_EAX[1] != 0)) {
      FUN_0056ca70();
    }
  }
  return;
}

