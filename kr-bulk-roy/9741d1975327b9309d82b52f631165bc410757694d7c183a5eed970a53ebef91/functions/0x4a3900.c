
void FUN_004a3900(undefined1 param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4)

{
  DWORD DVar1;
  DWORD *unaff_ESI;
  bool bVar2;
  undefined2 local_a;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  
  DVar1 = timeGetTime();
  if (500 < DVar1 - *unaff_ESI) {
    bVar2 = DAT_00fba798 == 0;
    *unaff_ESI = DVar1;
    local_a = 0x37;
    local_8 = param_1;
    local_7 = param_2;
    local_6 = param_3;
    local_5 = param_4;
    if (bVar2) {
      (**(code **)(*DAT_00fba854 + 0x10))(0,&local_a,6);
    }
  }
  return;
}

