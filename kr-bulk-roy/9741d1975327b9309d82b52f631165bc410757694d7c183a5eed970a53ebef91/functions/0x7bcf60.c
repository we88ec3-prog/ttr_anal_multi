
void FUN_007bcf60(void)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  char *in_ECX;
  int unaff_EDI;
  undefined1 auStack_a8 [4];
  LPCRITICAL_SECTION local_a4;
  uint local_a0 [4];
  undefined4 local_90;
  uint local_8c;
  uint local_84 [4];
  undefined4 local_74;
  uint local_70;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  uint local_5c;
  undefined4 local_4c;
  uint local_48;
  uint local_40;
  undefined4 local_30;
  uint local_2c;
  undefined4 local_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00914dd3;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_a8;
  ExceptionList = &local_14;
  local_a4 = (LPCRITICAL_SECTION)(unaff_EDI + 0x40);
  EnterCriticalSection(local_a4);
  local_70 = 0xf;
  local_74 = 0;
  local_84[0] = local_84[0] & 0xffffff00;
  pcVar3 = in_ECX;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  FUN_00402a70(in_ECX,(int)pcVar3 - (int)(in_ECX + 1));
  local_c = 0;
  local_8c = 0xf;
  local_90 = 0;
  local_a0[0] = local_a0[0] & 0xffffff00;
  pcVar3 = in_ECX;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  FUN_00402a70(in_ECX,(int)pcVar3 - (int)(in_ECX + 1));
  local_c._0_1_ = 1;
  local_68 = 1;
  local_64 = 3;
  local_60 = 0;
  local_48 = 0xf;
  local_4c = 0;
  local_5c = local_5c & 0xffffff00;
  FUN_00403040(local_a0,0,0xffffffff);
  local_c = CONCAT31(local_c._1_3_,2);
  local_2c = 0xf;
  local_30 = 0;
  local_40 = local_40 & 0xffffff00;
  FUN_00403040(local_84,0,0xffffffff);
  local_24 = 0;
  if (0xf < local_8c) {
    FUN_0089120c(local_a0[0]);
  }
  local_8c = 0xf;
  local_90 = 0;
  local_a0[0] = local_a0[0] & 0xffffff00;
  local_c = CONCAT31(local_c._1_3_,5);
  if (0xf < local_70) {
    FUN_0089120c(local_84[0]);
  }
  local_70 = 0xf;
  iVar2 = *(int *)(unaff_EDI + 0x34);
  local_74 = 0;
  local_84[0] = local_84[0] & 0xffffff00;
  iVar4 = FUN_007bd680(iVar2,*(undefined4 *)(iVar2 + 4),&local_68);
  if (*(int *)(unaff_EDI + 0x38) == 0x38e38e2) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("list<T> too long");
  }
  *(int *)(unaff_EDI + 0x38) = *(int *)(unaff_EDI + 0x38) + 1;
  *(int *)(iVar2 + 4) = iVar4;
  **(int **)(iVar4 + 4) = iVar4;
  SetEvent(*(HANDLE *)(unaff_EDI + 100));
  LeaveCriticalSection(local_a4);
  if (0xf < local_2c) {
    FUN_0089120c(local_40);
  }
  local_2c = 0xf;
  local_30 = 0;
  local_40 = local_40 & 0xffffff00;
  if (0xf < local_48) {
    FUN_0089120c(local_5c);
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_a8);
  return;
}

