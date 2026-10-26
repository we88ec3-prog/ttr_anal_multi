
void FUN_004a44e0(undefined1 param_1,undefined1 param_2,undefined1 param_3,byte param_4,byte param_5
                 ,undefined1 param_6)

{
  DWORD DVar1;
  DWORD *unaff_ESI;
  undefined2 local_c;
  undefined1 local_a;
  undefined1 local_9;
  undefined1 local_8;
  short local_7;
  undefined1 local_5;
  
  DVar1 = timeGetTime();
  if (500 < DVar1 - *unaff_ESI) {
    *unaff_ESI = DVar1;
    local_a = param_1;
    local_9 = param_2;
    local_c = 0x8d;
    local_8 = param_3;
    local_7 = (param_4 - 1) * 0x50 + (ushort)param_5;
    local_5 = param_6;
    if (DAT_00fba798 == 0) {
      (**(code **)(*DAT_00fba854 + 0x10))(0,&local_c,8);
    }
  }
  return;
}

