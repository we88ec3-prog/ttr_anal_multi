
void FUN_0082f660(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  void *_Src;
  int *in_ECX;
  uint *puVar3;
  uint local_250;
  int *local_248;
  undefined1 local_244 [36];
  int local_220;
  int local_21c;
  int local_218;
  int local_214;
  uint local_20c [129];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  piVar1 = (int *)FUN_00714770(param_1,&DAT_00bed1e0);
  if (piVar1 != (int *)0x0) {
    FUN_0082f3f0();
    (**(code **)(*piVar1 + 0x10))(local_244,0x234,1);
    if (*in_ECX == 0) {
      in_ECX[1] = local_220;
      in_ECX[3] = local_218;
      in_ECX[2] = local_21c;
      in_ECX[4] = local_214;
      *in_ECX = 1;
      in_ECX[5] = (int)((float)in_ECX[1] / (float)in_ECX[3]);
      in_ECX[6] = (int)((float)in_ECX[2] / (float)in_ECX[4]);
    }
    local_248 = in_ECX + 0x27;
    local_250 = 0;
    puVar3 = local_20c;
    do {
      if (puVar3[2] != 0) {
        iVar2 = FUN_0087dc3d(*puVar3);
        _Src = (void *)FUN_0087dc3d(-(uint)((int)((ulonglong)puVar3[2] * 4 >> 0x20) != 0) |
                                    (uint)((ulonglong)puVar3[2] * 4));
        (**(code **)(*piVar1 + 0x10))(iVar2,*puVar3,1);
        FUN_00727190(_Src);
        if (iVar2 != 0) {
          FUN_00891d3d(iVar2);
        }
        FUN_0082fc70(in_ECX,local_250);
        FID_conflict__memcpy(*(void **)(*local_248 + 0x14),_Src,puVar3[2] * 4);
        if (_Src != (void *)0x0) {
          FUN_00891d3d(_Src);
        }
      }
      local_248 = local_248 + 1;
      local_250 = local_250 + 1;
      puVar3 = puVar3 + 4;
    } while (local_250 < 0x20);
    FUN_0082fa80(in_ECX);
    (**(code **)(*piVar1 + 4))();
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

