
void FUN_007d9d80(char *param_1,undefined4 param_2)

{
  char cVar1;
  undefined1 uVar2;
  char *pcVar3;
  undefined2 *puVar4;
  char ****_Filename;
  FILE *_File;
  int *in_ECX;
  uint in_stack_0000001c;
  char in_stack_00000024;
  int local_428;
  int local_424;
  undefined1 local_420 [152];
  undefined1 local_388 [152];
  undefined1 local_2f0 [152];
  undefined1 local_258 [156];
  undefined1 local_1bc;
  undefined4 local_1ac;
  undefined4 local_1a8;
  undefined1 local_1a0 [152];
  undefined **local_108;
  uint local_bc;
  undefined4 local_ac;
  uint local_a8;
  char local_94;
  uint local_90 [4];
  undefined4 local_80;
  uint local_7c;
  char ***local_74 [4];
  undefined4 local_64;
  uint local_60;
  undefined1 local_58 [64];
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_0091c82e;
  local_10 = ExceptionList;
  local_18 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  if (param_1 == "") goto LAB_007da411;
  FUN_0072ed80();
  local_1a8 = 0xf;
  local_1ac = 0;
  local_1bc = 0;
  local_8._0_1_ = 2;
  local_60 = 0xf;
  local_64 = 0;
  local_74[0] = (char ***)((uint)local_74[0] & 0xffffff00);
  FUN_00403040(&param_2,0,0xffffffff);
  local_8._0_1_ = 3;
  if (in_stack_00000024 == '\0') {
    pcVar3 = param_1;
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    FUN_00401fc0(param_1,(int)pcVar3 - (int)(param_1 + 1));
  }
  FUN_0072e420(local_388,"Animation");
  local_8._0_1_ = 4;
  FUN_0072e420(local_2f0,"AnimationHeader");
  local_8._0_1_ = 5;
  puVar4 = (undefined2 *)(**(code **)(*in_ECX + 0x40))();
  FUN_00730d80(local_58,&DAT_00c0d6dc,*puVar4);
  FUN_0072e770(local_2f0,&DAT_00bfb82c);
  local_7c = 0xf;
  local_80 = 0;
  local_90[0] = local_90[0] & 0xffffff00;
  FUN_00402a70(&DAT_00c0ce30,4);
  local_8._0_1_ = 6;
  FUN_0072e890(local_90,puVar4 + 2);
  local_8._0_1_ = 5;
  if (0xf < local_7c) {
    FUN_0089120c();
  }
  FUN_0072e420(local_258,"AnimationData");
  local_8._0_1_ = 7;
  pcVar3 = "true";
  if (*(char *)(puVar4 + 0x10) == '\0') {
    pcVar3 = "false";
  }
  FUN_00730d80(local_58,&DAT_00bfc638,pcVar3);
  FUN_0072e770(local_258,"CameraAttach");
  pcVar3 = "true";
  if (*(char *)((int)puVar4 + 0x21) == '\0') {
    pcVar3 = "false";
  }
  FUN_00730d80(local_58,&DAT_00bfc638,pcVar3);
  FUN_0072e770(local_258,"Repeat");
  FUN_0072e710((double)*(float *)(puVar4 + 0x12));
  FUN_00730d80(local_58,&DAT_00c0d6dc);
  FUN_0072e770(local_258,"LagtimeType");
  FUN_00730d80(local_58,&DAT_00c0d6dc);
  FUN_0072e770(local_258,"FaceIndex");
  FUN_00730d80(local_58,&DAT_00c0d6dc);
  FUN_0072e770(local_258,"Counter");
  FUN_0072e1e0();
  FUN_0072e420(local_420,"ReferIndex");
  local_8._0_1_ = 8;
  uVar2 = (undefined1)local_8;
  local_8._0_1_ = 8;
  local_428 = 0;
  if (0 < *(int *)(puVar4 + 0x52)) {
    local_424 = 0;
    do {
      FUN_0072e420(local_1a0,"SpliteData");
      local_8._0_1_ = 9;
      FUN_00730d80(local_58,&DAT_00c444f4,*(undefined4 *)(local_424 + *(int *)(puVar4 + 0x54)));
      FUN_0072e770(local_1a0,"FileID");
      FUN_0072e710((double)*(float *)(local_424 + 4 + *(int *)(puVar4 + 0x54)));
      FUN_0072e710((double)*(float *)(local_424 + 8 + *(int *)(puVar4 + 0x54)));
      FUN_0072e710((double)*(float *)(local_424 + 0xc + *(int *)(puVar4 + 0x54)));
      FUN_0072e710((double)*(float *)(local_424 + 0x10 + *(int *)(puVar4 + 0x54)));
      FUN_0072e1e0();
      local_8._0_1_ = 8;
      FUN_0072e520();
      local_424 = local_424 + 0x14;
      local_428 = local_428 + 1;
      uVar2 = (undefined1)local_8;
    } while (local_428 < *(int *)(puVar4 + 0x52));
  }
  local_8._0_1_ = uVar2;
  FUN_0072e1e0();
  if (*(int *)(puVar4 + 0x16) != 0) {
    FUN_0072e420(local_1a0,"Effect");
    local_8._0_1_ = 10;
    FUN_0072e770(local_1a0,&DAT_00c0d66c);
    FUN_0072e770(local_1a0,"Folder");
    FUN_0072e1e0();
    local_8._0_1_ = 8;
    FUN_0072e520();
  }
  if (*(int *)(puVar4 + 0x34) != 0) {
    FUN_0072e420(local_1a0,"Sound");
    local_8._0_1_ = 0xb;
    FUN_0072e770(local_1a0,&DAT_00c0d66c);
    FUN_0072e770(local_1a0,"Folder");
    FUN_0072e1e0();
    local_8._0_1_ = 8;
    FUN_0072e520();
  }
  FUN_0072e1e0();
  FUN_0072e1e0();
  if (in_stack_00000024 == '\0') {
    _Filename = (char ****)local_74[0];
    if (local_60 < 0x10) {
      _Filename = local_74;
    }
    _File = _fopen((char *)_Filename,"w");
    if (_File != (FILE *)0x0) {
      if (local_94 != '\0') {
        FID_conflict__fputc(0xef,_File);
        FID_conflict__fputc(0xbb,_File);
        FID_conflict__fputc(0xbf,_File);
      }
      (*(code *)local_108[1])(_File);
LAB_007da35e:
      _ferror(_File);
      _fclose(_File);
    }
  }
  else {
    _File = _fopen(param_1,"w");
    if (_File != (FILE *)0x0) {
      if (local_94 != '\0') {
        FID_conflict__fputc(0xef,_File);
        FID_conflict__fputc(0xbb,_File);
        FID_conflict__fputc(0xbf,_File);
      }
      (*(code *)local_108[1])(_File);
      goto LAB_007da35e;
    }
  }
  local_8._0_1_ = 7;
  FUN_0072e520();
  local_8._0_1_ = 5;
  FUN_0072e520();
  local_8._0_1_ = 4;
  FUN_0072e520();
  local_8 = CONCAT31(local_8._1_3_,3);
  FUN_0072e520();
  if (0xf < local_60) {
    FUN_0089120c();
  }
  local_8 = local_8 & 0xffffff00;
  local_60 = 0xf;
  local_64 = 0;
  local_74[0] = (char ***)((uint)local_74[0] & 0xffffff00);
  local_108 = TiXmlDocument::vftable;
  if (0xf < local_a8) {
    FUN_0089120c();
  }
  local_a8 = 0xf;
  local_ac = 0;
  local_bc = local_bc & 0xffffff00;
  FUN_0072e040();
LAB_007da411:
  if (0xf < in_stack_0000001c) {
    FUN_0089120c();
  }
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

