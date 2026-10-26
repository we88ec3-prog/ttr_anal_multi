
void FUN_006d3b90(void)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  FILE *_File;
  int in_ECX;
  undefined4 *puVar6;
  undefined1 local_36c [152];
  undefined1 local_2d4 [152];
  undefined1 local_23c [152];
  undefined1 local_1a4 [152];
  undefined **local_10c [19];
  uint local_c0;
  undefined4 local_b0;
  uint local_ac;
  char local_98;
  undefined1 local_94 [64];
  undefined1 local_54 [64];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00919b37;
  local_10 = ExceptionList;
  uVar5 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar5;
  FUN_0072ed80(local_10c);
  local_8 = 0;
  FUN_0072fc40(local_36c,"euc-kr");
  local_8._0_1_ = 1;
  FUN_0072e420(local_2d4,"KEYMAPEXTRA");
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_0072e1e0(uVar5);
  puVar2 = *(undefined4 **)(in_ECX + 0x28);
  puVar6 = (undefined4 *)*puVar2;
  while (puVar6 != puVar2) {
    FUN_0072e420(local_1a4,&DAT_00bf2330);
    local_8 = CONCAT31(local_8._1_3_,3);
    FUN_00730d80(local_94,&DAT_00c0d6dc,puVar6[3]);
    FUN_0072e770(local_1a4,&DAT_00bfb82c);
    uVar5 = 0;
    if ((int)(puVar6[5] - puVar6[4]) >> 2 != 0) {
      do {
        FUN_0072e420(local_23c,"VALUE");
        local_8._0_1_ = 4;
        FUN_00730d80(local_54,&DAT_00c0d6dc,*(undefined4 *)(puVar6[4] + uVar5 * 4));
        FUN_0072e770(local_23c,"KeyCode");
        FUN_0072e1e0();
        local_8 = CONCAT31(local_8._1_3_,3);
        FUN_0072e520();
        uVar5 = uVar5 + 1;
      } while (uVar5 < (uint)((int)(puVar6[5] - puVar6[4]) >> 2));
    }
    FUN_0072e1e0();
    if (*(char *)((int)puVar6 + 0x21) == '\0') {
      puVar3 = (undefined4 *)puVar6[2];
      if (*(char *)((int)puVar3 + 0x21) == '\0') {
        cVar1 = *(char *)((int)*puVar3 + 0x21);
        puVar6 = puVar3;
        puVar3 = (undefined4 *)*puVar3;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar3 + 0x21);
          puVar6 = puVar3;
          puVar3 = (undefined4 *)*puVar3;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar6[1] + 0x21);
        puVar4 = (undefined4 *)puVar6[1];
        puVar3 = puVar6;
        while ((puVar6 = puVar4, cVar1 == '\0' && (puVar3 == (undefined4 *)puVar6[2]))) {
          cVar1 = *(char *)((int)puVar6[1] + 0x21);
          puVar4 = (undefined4 *)puVar6[1];
          puVar3 = puVar6;
        }
      }
    }
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_0072e520();
  }
  FUN_0072e1e0();
  _File = _fopen("VirualkeyExtra.dll","w");
  if (_File != (FILE *)0x0) {
    if (local_98 != '\0') {
      FID_conflict__fputc(0xef,_File);
      FID_conflict__fputc(0xbb,_File);
      FID_conflict__fputc(0xbf,_File);
    }
    (*(code *)local_10c[0][1])(_File,0);
    _ferror(_File);
    _fclose(_File);
  }
  local_8._0_1_ = 1;
  FUN_0072e520();
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_005902f0();
  local_8 = 0xffffffff;
  local_10c[0] = TiXmlDocument::vftable;
  if (0xf < local_ac) {
    FUN_0089120c(local_c0);
  }
  local_ac = 0xf;
  local_b0 = 0;
  local_c0 = local_c0 & 0xffffff00;
  FUN_0072e040();
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

