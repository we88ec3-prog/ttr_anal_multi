
void FUN_007176a0(undefined4 *param_1)

{
  char *pcVar1;
  char cVar2;
  uint uVar3;
  char *pcVar4;
  undefined4 *_Src;
  int in_ECX;
  int iVar5;
  undefined4 local_4c [5];
  uint local_38;
  uint local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009196b9;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  param_1[4] = 0;
  pcVar1 = (char *)(in_ECX + 0xc);
  param_1[5] = 0xf;
  *(undefined1 *)param_1 = 0;
  pcVar4 = pcVar1;
  do {
    cVar2 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar2 != '\0');
  local_14 = uVar3;
  FUN_00402a70(pcVar1,(int)pcVar4 - (in_ECX + 0xd));
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = local_30[0] & 0xffffff00;
  local_8 = 1;
  iVar5 = *(int *)(in_ECX + 4);
  if (iVar5 != 0) {
    do {
      iVar5 = *(int *)(iVar5 + 4);
      if (iVar5 == 0) break;
      pcVar4 = pcVar1;
      do {
        cVar2 = *pcVar4;
        pcVar4 = pcVar4 + 1;
      } while (cVar2 != '\0');
      FUN_00402a70(pcVar1,(int)pcVar4 - (in_ECX + 0xd));
      FUN_00401fc0(&DAT_00bed1e4,1);
      _Src = (undefined4 *)FUN_00543500(local_4c,local_30,param_1,uVar3);
      if (param_1 != _Src) {
        if (0xf < (uint)param_1[5]) {
          FUN_0089120c(*param_1);
        }
        param_1[5] = 0xf;
        param_1[4] = 0;
        *(undefined1 *)param_1 = 0;
        if ((uint)_Src[5] < 0x10) {
          FID_conflict__memcpy(param_1,_Src,_Src[4] + 1);
        }
        else {
          *param_1 = *_Src;
          *_Src = 0;
        }
        param_1[4] = _Src[4];
        param_1[5] = _Src[5];
        _Src[5] = 0xf;
        _Src[4] = 0;
        *(undefined1 *)_Src = 0;
      }
      local_8 = CONCAT31(local_8._1_3_,1);
      if (0xf < local_38) {
        FUN_0089120c(local_4c[0]);
      }
    } while (iVar5 != 0);
    if (0xf < local_1c) {
      FUN_0089120c(local_30[0]);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

