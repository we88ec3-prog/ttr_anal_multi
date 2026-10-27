
void FUN_0056cd10(void)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  undefined4 ****ppppuVar5;
  int *unaff_EDI;
  undefined4 uVar6;
  undefined1 auStack_48 [4];
  undefined4 local_44;
  undefined4 local_40;
  int local_3c;
  undefined4 ***local_38 [4];
  undefined4 local_28;
  uint local_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00938604;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_48;
  ExceptionList = &local_14;
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 0;
    FUN_004dec90(DAT_00d61f20 ^ (uint)&stack0xffffffb0);
    _atexit((_func_4879 *)&LAB_00bcce30);
  }
  local_c = 0xffffffff;
  if ((*(char *)(DAT_00fab134 + 0x36) == '\x05') || (*(char *)(DAT_00fab134 + 0x36) == '\0')) {
    local_3c = 1;
  }
  else {
    local_3c = 0;
  }
  FUN_0056fde0(*unaff_EDI + 0x20);
  local_24 = 0xf;
  local_28 = 0;
  local_38[0] = (undefined4 ***)((uint)local_38[0] & 0xffffff00);
  FUN_00402a70("Map/Minimap/",0xc);
  local_c = 1;
  if ((DAT_00fb75b0 & 1) == 0) {
    DAT_00fb75b0 = DAT_00fb75b0 | 1;
    local_c._0_1_ = 2;
    local_c._1_3_ = 0;
    FUN_004f3d80();
    _atexit((_func_4879 *)&LAB_00bcd1e0);
    local_c = CONCAT31(local_c._1_3_,1);
  }
  pcVar3 = (char *)FUN_004f7df0();
  if (0xf < *(uint *)(pcVar3 + 0x14)) {
    pcVar3 = *(char **)pcVar3;
  }
  pcVar4 = pcVar3;
  do {
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  if (pcVar4 == pcVar3 + 1) {
    FUN_00402a70(&DAT_00bf2375,0);
  }
  else {
    pcVar4 = pcVar3;
    do {
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    FUN_00401fc0(pcVar3,(int)pcVar4 - (int)(pcVar3 + 1));
    FUN_00401fc0(&DAT_00c107fc,4);
  }
  ppppuVar5 = (undefined4 ****)local_38[0];
  if (local_24 < 0x10) {
    ppppuVar5 = local_38;
  }
  FUN_0056e790(ppppuVar5,local_3c == 0);
  FUN_0056e6e0();
  iVar2 = *(int *)(DAT_00fba838 + 0x40);
  if (iVar2 == 0) {
    uVar6 = 0;
  }
  else {
    uVar6 = *(undefined4 *)(iVar2 + 0x15c);
    local_44 = *(undefined4 *)(iVar2 + 0x158);
    local_40 = uVar6;
  }
  *(undefined4 *)(*unaff_EDI + 100) = uVar6;
  if (0xf < local_24) {
    FUN_0089120c(local_38[0]);
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_48);
  return;
}

