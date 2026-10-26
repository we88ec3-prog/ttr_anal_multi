
void FUN_0064e6c0(char param_1)

{
  code *pcVar1;
  char cVar2;
  void *unaff_ESI;
  int *unaff_EDI;
  void *pvStack_18;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_0093d7bc;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  cVar2 = FUN_0064e8a0(DAT_00d61f20 ^ (uint)&stack0xffffffd8);
  if (cVar2 == '\0') {
    (**(code **)(*(int *)unaff_EDI[0x3d] + 0x94))(0);
    ExceptionList = pvStack_18;
    return;
  }
  pcVar1 = *(code **)(*(int *)unaff_EDI[0x3d] + 0x94);
  if (param_1 == '\0') {
    (*pcVar1)(0);
    FUN_00749a00(0,0);
    (**(code **)(*unaff_EDI + 0xbc))
              (unaff_EDI[2],unaff_EDI[3],unaff_EDI[2] + 0xc6,unaff_EDI[3] + 0xb8);
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      FUN_0054f850();
      _atexit((_func_4879 *)&LAB_00bcd580);
    }
    DAT_00fb934d = 0;
    if (DAT_00fb934e == 0) goto LAB_0064e83a;
  }
  else {
    (*pcVar1)(1);
    FUN_00749a00(0xc6,0);
    (**(code **)(*unaff_EDI + 0xbc))
              (unaff_EDI[2],unaff_EDI[3],unaff_EDI[2] + 0x18c,unaff_EDI[3] + 0xb8);
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      FUN_0054f850();
      _atexit((_func_4879 *)&LAB_00bcd580);
    }
    DAT_00fb934d = DAT_00fb934f != '\0';
    if (DAT_00fb934e <= (DAT_00fb934f != '\0')) goto LAB_0064e83a;
  }
  DAT_00fb934d = DAT_00fb934e;
LAB_0064e83a:
  if ((unaff_EDI[0x18] != 0) && (((int *)unaff_EDI[7])[2] != 6)) {
    (**(code **)(*(int *)unaff_EDI[7] + 0x30))();
  }
  *(char *)(unaff_EDI + 0x41) = param_1;
  ExceptionList = unaff_ESI;
  return;
}

