
void FUN_007dae40(undefined4 param_1)

{
  short *psVar1;
  char *pcVar2;
  int *in_ECX;
  float10 fVar3;
  undefined1 auStack_2b4 [52];
  undefined4 local_280;
  uint auStack_27c [4];
  undefined4 uStack_26c;
  uint uStack_268;
  undefined1 auStack_260 [152];
  undefined1 auStack_1c8 [64];
  undefined1 auStack_188 [260];
  uint local_84;
  void *local_4c;
  undefined1 *puStack_48;
  undefined4 uStack_44;
  
  uStack_44 = 0xffffffff;
  puStack_48 = &LAB_0091c6dc;
  local_4c = ExceptionList;
  local_84 = DAT_00d61f20 ^ (uint)auStack_2b4;
  ExceptionList = &local_4c;
  local_280 = param_1;
  psVar1 = (short *)(**(code **)(*in_ECX + 0x40))(DAT_00d61f20 ^ (uint)&stack0xfffffd40);
  if (*psVar1 != 0) {
    FUN_0072e420(auStack_260,"Animation");
    uStack_44 = 0;
    FUN_00730d80(auStack_1c8,&DAT_00c0d6dc,*psVar1);
    FUN_0072e770(auStack_260,&DAT_00bfb82c);
    uStack_268 = 0xf;
    uStack_26c = 0;
    auStack_27c[0] = auStack_27c[0] & 0xffffff00;
    FUN_00402a70(&DAT_00c0d66c,4);
    uStack_44._0_1_ = 1;
    FUN_0072e890(auStack_27c,psVar1 + 2);
    uStack_44._0_1_ = 0;
    if (0xf < uStack_268) {
      FUN_0089120c();
    }
    pcVar2 = "true";
    if ((char)psVar1[0x10] == '\0') {
      pcVar2 = "false";
    }
    FUN_00730d80(auStack_1c8,&DAT_00bfc638,pcVar2);
    FUN_0072e770(auStack_260,"CameraAttach");
    FUN_00730da0(auStack_188,&DAT_00c420d8,(double)*(float *)(psVar1 + 0x52));
    FUN_0072e770(auStack_260,"FrameSpeed");
    FUN_00730d80(auStack_1c8,&DAT_00c0d6dc,*(undefined1 *)((int)psVar1 + 0x29));
    FUN_0072e770(auStack_260,"FaceIndex");
    FUN_00730d80(auStack_1c8,&DAT_00c0d6dc,*(undefined1 *)((int)psVar1 + 0x21));
    FUN_0072e770(auStack_260,"Repeat");
    FUN_00730da0(auStack_188,&DAT_00c420d8,(double)*(float *)(psVar1 + 0x12));
    FUN_0072e770(auStack_260,"RepeatStartFrame");
    FUN_00730d80(auStack_1c8,&DAT_00c0d6dc,(char)psVar1[0x14]);
    FUN_0072e770(auStack_260,"LagtimeType");
    fVar3 = (float10)(**(code **)(*in_ECX + 0xc))();
    FUN_00730da0(auStack_188,&DAT_00c420d8,(double)fVar3);
    FUN_0072e770(auStack_260,"Length");
    if (*(int *)(psVar1 + 0x16) != 0) {
      FUN_0072e420(auStack_188,"Effect");
      uStack_44._0_1_ = 2;
      FUN_0072e770(auStack_188,&DAT_00c0d66c);
      FUN_0072e770(auStack_188,"Folder");
      FUN_0072e1e0();
      uStack_44._0_1_ = 0;
      FUN_0072e520();
    }
    if (*(int *)(psVar1 + 0x34) != 0) {
      FUN_0072e420(auStack_188,"Sound");
      uStack_44._0_1_ = 3;
      FUN_0072e770(auStack_188,&DAT_00c0d66c);
      FUN_0072e770(auStack_188,"Folder");
      FUN_0072e1e0();
      uStack_44._0_1_ = 0;
      FUN_0072e520();
    }
    FUN_0072e1e0();
    uStack_44 = 0xffffffff;
    FUN_0072e520();
  }
  ExceptionList = local_4c;
  __security_check_cookie(local_84 ^ (uint)auStack_2b4);
  return;
}

