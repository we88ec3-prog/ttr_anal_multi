
void FUN_00501650(ushort param_1)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  short sVar4;
  undefined2 local_c;
  short local_a;
  ushort local_8;
  
  sVar4 = 0;
  iVar2 = FUN_0040f060();
  iVar1 = *(int *)(*(int *)(iVar2 + 4) + 0x10);
  iVar2 = (*(int *)(*(int *)(iVar2 + 4) + 0x14) - iVar1) / 0x18;
  if (iVar2 != 0) {
    puVar3 = (uint *)(iVar1 + 0xc);
    do {
      if ((((short)puVar3[-2] == 0xb) && (*puVar3 == (uint)param_1)) &&
         ((short)puVar3[-1] < *(short *)((int)puVar3 + -6))) {
        sVar4 = (short)puVar3[2];
      }
      puVar3 = puVar3 + 6;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    if (sVar4 != 0) {
      local_c = 0xdf;
      local_8 = param_1;
      if (DAT_00fba798 == 0) {
        local_a = sVar4;
        (**(code **)(*DAT_00fba854 + 0x10))(0,&local_c,6);
      }
    }
  }
  return;
}

