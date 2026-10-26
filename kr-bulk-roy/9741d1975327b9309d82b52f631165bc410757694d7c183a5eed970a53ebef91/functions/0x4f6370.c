
void FUN_004f6370(void)

{
  char cVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  char *pcVar5;
  undefined4 uVar6;
  undefined1 local_280 [8];
  int *local_278;
  uint local_274 [4];
  undefined4 local_264;
  uint local_260;
  uint local_258;
  undefined4 local_248;
  uint local_244;
  uint local_23c [4];
  undefined4 local_22c;
  uint local_228;
  uint local_220 [4];
  undefined4 local_210;
  uint local_20c;
  char local_204 [260];
  char local_100 [52];
  char local_cc [132];
  char local_48 [52];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092223c;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  builtin_strncpy(local_cc,"Table/_SoundList.txt",0x15);
  local_14 = uVar2;
  _memset(local_cc + 0x15,0,0x6b);
  piVar3 = (int *)FUN_00714770(local_cc,&DAT_00bed1e0);
  local_278 = piVar3;
  if (piVar3 != (int *)0x0) {
    while (iVar4 = (**(code **)(*piVar3 + 8))(local_204,0x100,uVar2), iVar4 != 0) {
      FID_conflict__sscanf(local_204,"%s %s",local_48,0x32,local_100,0x32);
      if (local_48[0] != '!') {
        pcVar5 = local_48;
        local_20c = 0xf;
        local_210 = 0;
        local_220[0] = local_220[0] & 0xffffff00;
        do {
          cVar1 = *pcVar5;
          pcVar5 = pcVar5 + 1;
        } while (cVar1 != '\0');
        FUN_00402a70(local_48,(int)pcVar5 - (int)(local_48 + 1));
        local_8 = 0;
        pcVar5 = local_100;
        local_228 = 0xf;
        local_22c = 0;
        local_23c[0] = local_23c[0] & 0xffffff00;
        do {
          cVar1 = *pcVar5;
          pcVar5 = pcVar5 + 1;
        } while (cVar1 != '\0');
        FUN_00402a70(local_100,(int)pcVar5 - (int)(local_100 + 1));
        local_8._0_1_ = 1;
        local_260 = 0xf;
        local_264 = 0;
        local_274[0] = local_274[0] & 0xffffff00;
        FUN_00403040(local_220,0,0xffffffff);
        local_8._0_1_ = 2;
        local_244 = 0xf;
        local_248 = 0;
        local_258 = local_258 & 0xffffff00;
        FUN_00403040(local_23c,0,0xffffffff);
        local_8 = CONCAT31(local_8._1_3_,3);
        uVar6 = FUN_004f9990(local_274);
        FUN_004f9180(&DAT_00fb7550,local_280,uVar6);
        if (0xf < local_244) {
          FUN_0089120c(local_258);
        }
        local_244 = 0xf;
        local_248 = 0;
        local_258 = local_258 & 0xffffff00;
        if (0xf < local_260) {
          FUN_0089120c(local_274[0]);
        }
        local_260 = 0xf;
        local_264 = 0;
        local_274[0] = local_274[0] & 0xffffff00;
        if (0xf < local_228) {
          FUN_0089120c(local_23c[0]);
        }
        local_8 = 0xffffffff;
        local_228 = 0xf;
        local_22c = 0;
        local_23c[0] = local_23c[0] & 0xffffff00;
        if (0xf < local_20c) {
          FUN_0089120c(local_220[0]);
        }
        local_20c = 0xf;
        local_210 = 0;
        local_220[0] = local_220[0] & 0xffffff00;
        piVar3 = local_278;
      }
    }
    (**(code **)(*piVar3 + 4))();
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

