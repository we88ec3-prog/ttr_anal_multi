
void FUN_0055bbe0(short *param_1,undefined4 param_2,undefined2 param_3,undefined4 param_4,
                 undefined4 param_5,int param_6)

{
  short sVar1;
  short *psVar2;
  undefined4 *in_ECX;
  int iVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00922fee;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fcde44 & 1) == 0) {
    DAT_00fcde44 = DAT_00fcde44 | 1;
    local_8 = 0;
    FUN_0055b8a0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit(FUN_00bcdef0);
  }
  local_8 = 0xffffffff;
  if (DAT_00fd2b78 != 0x104) {
    iVar3 = DAT_00fd2b78 * 0x4c;
    DAT_00fd2b78 = DAT_00fd2b78 + 1;
    if ((undefined2 *)(&DAT_00fcde48 + iVar3) != (undefined2 *)0x0) {
      *(undefined4 *)(&DAT_00fcde4c + iVar3) = *in_ECX;
      *(undefined4 *)(&DAT_00fcde50 + iVar3) = in_ECX[1];
      *(undefined4 *)(&DAT_00fcde54 + iVar3) = in_ECX[2];
      *(undefined4 *)(&DAT_00fcde58 + iVar3) = in_ECX[3];
      psVar2 = param_1;
      do {
        sVar1 = *psVar2;
        psVar2 = psVar2 + 1;
      } while (sVar1 != 0);
      FUN_00402160(param_1,(int)psVar2 - (int)(param_1 + 1) >> 1);
      *(undefined4 *)(&DAT_00fcde7c + iVar3) = param_4;
      *(undefined4 *)(&DAT_00fcde80 + iVar3) = param_5;
      *(undefined4 *)(&DAT_00fcde5c + iVar3) = param_2;
      *(undefined2 *)(&DAT_00fcde48 + iVar3) = param_3;
      FUN_00523e40(iVar3 + 0xfcde84);
      if (param_6 != 0) {
        FUN_00443d10();
      }
    }
  }
  ExceptionList = local_10;
  return;
}

