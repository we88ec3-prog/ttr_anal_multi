
/* WARNING: Removing unreachable block (ram,0x0073d27f) */
/* WARNING: Removing unreachable block (ram,0x0073d29f) */

void FUN_0073d170(void)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  char ****ppppcVar4;
  char ****ppppcVar5;
  undefined4 *unaff_ESI;
  int *unaff_FS_OFFSET;
  char ***local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  int local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091f2c3;
  local_10 = *unaff_FS_OFFSET;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  *unaff_FS_OFFSET = (int)&local_10;
  local_14 = uVar2;
  iVar3 = FUN_008bdae0();
  if (iVar3 != 0) {
    FID_conflict__wprintf("ERR: Failed to initialize freetype2\n",uVar2);
  }
  unaff_ESI[1] = *unaff_ESI;
  local_8 = 0;
  FUN_00402160(L"Tahoma",6);
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = (char ***)((uint)local_30[0] & 0xffffff00);
  local_8._0_1_ = 2;
  FUN_00429710();
  local_8 = CONCAT31(local_8._1_3_,3);
  ppppcVar5 = (char ****)local_30[0];
  if (local_1c < 0x10) {
    ppppcVar5 = local_30;
  }
  ppppcVar4 = ppppcVar5;
  do {
    cVar1 = *(char *)ppppcVar4;
    ppppcVar4 = (char ****)((int)ppppcVar4 + 1);
  } while (cVar1 != '\0');
  FUN_00402a70(ppppcVar5,(int)ppppcVar4 - (int)((int)ppppcVar5 + 1));
  if (0xf < local_1c) {
    FUN_0089120c(local_30[0]);
  }
  local_8 = local_8 & 0xffffff00;
  local_30[0] = (char ***)((uint)local_30[0] & 0xffffff00);
  local_1c = 0xf;
  local_20 = 0;
  FUN_0073d410(unaff_ESI);
  *unaff_FS_OFFSET = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

