
void FUN_004a4560(byte param_1,byte param_2,byte param_3,byte param_4)

{
  DWORD DVar1;
  DWORD *unaff_ESI;
  undefined2 local_a;
  short local_8;
  short local_6;
  
  DVar1 = timeGetTime();
  if (500 < DVar1 - *unaff_ESI) {
    *unaff_ESI = DVar1;
    local_a = 0x8e;
    local_8 = (param_1 - 1) * 0x50 + (ushort)param_2;
    local_6 = (param_3 - 1) * 0x50 + (ushort)param_4;
    if (DAT_00fba798 == 0) {
      (**(code **)(*DAT_00fba854 + 0x10))(0,&local_a,6);
    }
  }
  return;
}

