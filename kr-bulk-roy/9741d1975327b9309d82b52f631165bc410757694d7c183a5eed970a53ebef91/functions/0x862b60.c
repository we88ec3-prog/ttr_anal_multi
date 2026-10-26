
bool FUN_00862b60(int *param_1)

{
  int *piVar1;
  undefined4 *in_EAX;
  int iVar2;
  int unaff_ESI;
  undefined4 local_8;
  
  iVar2 = ((*(int *)(unaff_ESI + 0x2c) - *(int *)(unaff_ESI + 0x28)) / 0xc) * 6;
  if (iVar2 != 0) {
    iVar2 = (**(code **)(*param_1 + 0x6c))(param_1,iVar2,8,0x65,1);
    if (-1 < iVar2) {
      local_8 = 0;
      iVar2 = (**(code **)(*(int *)*in_EAX + 0x2c))((int *)*in_EAX,0,0,&local_8,0);
      if (-1 < iVar2) {
        iVar2 = FUN_00862980(local_8);
        piVar1 = (int *)*in_EAX;
        if (iVar2 != 0) {
          iVar2 = (**(code **)(*piVar1 + 0x30))(piVar1);
          return -1 < iVar2;
        }
        (**(code **)(*piVar1 + 0x30))(piVar1);
      }
    }
  }
  return false;
}

