
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Removing unreachable block (ram,0x0071417a) */

void FUN_00714030(void)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  char *pcVar4;
  int iVar5;
  DWORD DVar6;
  undefined4 in_ECX;
  uint uVar7;
  char *unaff_EDI;
  undefined1 local_1014;
  undefined1 local_1013 [4095];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091974b;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  uVar7 = DAT_00fe364c;
  local_14 = uVar2;
  if ((DAT_00fe364c & 1) == 0) {
    uVar7 = DAT_00fe364c | 1;
    DAT_00fe3648 = '\0';
    DAT_00fe364c = uVar7;
    _memset(&DAT_00fe3548,0,0x100);
  }
  if (DAT_00fe3648 != '\0') {
    if ((uVar7 & 1) == 0) {
      DAT_00fe364c = uVar7 | 1;
      DAT_00fe3648 = '\0';
      _memset(&DAT_00fe3548,0,0x100);
    }
    pcVar4 = &DAT_00fe3548;
    do {
      pcVar3 = pcVar4;
      pcVar4 = pcVar3 + 1;
    } while (*pcVar3 != '\0');
    FUN_00402a70(&DAT_00fe3548,pcVar3 + -0xfe3548);
    local_8 = 0;
    pcVar4 = unaff_EDI;
    do {
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    FUN_00401fc0(unaff_EDI,(int)pcVar4 - (int)(unaff_EDI + 1));
    iVar5 = FUN_00717b60(uVar2);
    if ((iVar5 == 0) || (iVar5 = FUN_00717bc0(), iVar5 == 0)) {
      iVar5 = FUN_00713cc0(in_ECX);
    }
    local_8 = 0xffffffff;
    if (iVar5 != 0) goto LAB_0071423d;
  }
  iVar5 = FUN_00717b60(uVar2);
  if (((iVar5 == 0) || (iVar5 = FUN_00717bc0(), iVar5 == 0)) &&
     (iVar5 = FUN_00713cc0(in_ECX), iVar5 == 0)) {
    DVar6 = GetLastError();
    if (DVar6 == 2) {
      pcVar4 = "File doesn\'t exist";
    }
    else {
      pcVar4 = "Path doesn\'t exist";
      if (DVar6 != 3) {
        pcVar4 = "Unknown";
      }
    }
    local_1014 = 0;
    _memset(local_1013,0,0xfff);
    FUN_00714950("File Open Error %d (%s): file %s, mode %s",DVar6,pcVar4);
    (*(code *)PTR_FUN_00d63d50)(&local_1014);
  }
LAB_0071423d:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

