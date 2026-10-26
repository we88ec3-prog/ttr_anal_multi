
void FUN_0072f110(undefined4 param_1)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  int *piVar4;
  char *in_ECX;
  int unaff_ESI;
  undefined **local_38;
  undefined1 local_31;
  uint local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00914bf8;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = local_30[0] & 0xffffff00;
  pcVar3 = in_ECX;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  local_14 = uVar2;
  FUN_00402a70(in_ECX,(int)pcVar3 - (int)(in_ECX + 1));
  piVar4 = (int *)(unaff_ESI + 0x20);
  local_8 = 0;
  FUN_00403040(local_30,0,0xffffffff);
  if (0xf < *(uint *)(unaff_ESI + 0x34)) {
    piVar4 = (int *)*piVar4;
  }
  piVar4 = (int *)FUN_00714770(piVar4,&DAT_00bed1e0,uVar2);
  if (piVar4 == (int *)0x0) {
    if (*(char *)(unaff_ESI + 0x44) == '\0') {
      *(undefined1 *)(unaff_ESI + 0x44) = 1;
      *(undefined4 *)(unaff_ESI + 0x48) = 2;
      pcVar3 = PTR_s_Failed_to_open_file_00d63c90;
      do {
        cVar1 = *pcVar3;
        pcVar3 = pcVar3 + 1;
      } while (cVar1 != '\0');
      FUN_00402a70(PTR_s_Failed_to_open_file_00d63c90,
                   (int)pcVar3 - (int)(PTR_s_Failed_to_open_file_00d63c90 + 1));
      *(undefined4 *)(unaff_ESI + 0x70) = 0xffffffff;
      *(undefined4 *)(unaff_ESI + 0x6c) = 0xffffffff;
      local_38 = TiXmlErrorReporter::vftable;
      FUN_00731de0(&local_38,0,0,0);
    }
    if (0xf < local_1c) {
      FUN_0089120c(local_30[0]);
    }
  }
  else {
    local_31 = FUN_0072f260(param_1);
    (**(code **)(*piVar4 + 4))();
    if (0xf < local_1c) {
      FUN_0089120c(local_30[0]);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

