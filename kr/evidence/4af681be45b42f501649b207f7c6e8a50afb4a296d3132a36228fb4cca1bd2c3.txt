
void FUN_0082f850(int *param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  void *_Src;
  undefined4 *puVar3;
  int *local_54c;
  uint local_548;
  undefined1 local_544 [36];
  int local_520;
  int local_51c;
  int local_518;
  int local_514;
  undefined4 local_4f4 [315];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  piVar1 = (int *)FUN_00714770(param_2,&DAT_00bed1e0);
  if (piVar1 != (int *)0x0) {
    FUN_0082f430();
    (**(code **)(*piVar1 + 0x10))(local_544,0x534,1);
    if (*param_1 == 0) {
      param_1[1] = local_520;
      param_1[3] = local_518;
      param_1[2] = local_51c;
      param_1[4] = local_514;
      *param_1 = 1;
      param_1[5] = (int)((float)param_1[1] / (float)param_1[3]);
      param_1[6] = (int)((float)param_1[2] / (float)param_1[4]);
    }
    local_54c = param_1 + 0x27;
    local_548 = 0;
    puVar3 = local_4f4;
    do {
      if (puVar3[2] != 0) {
        iVar2 = FUN_0087dc3d(*puVar3);
        _Src = (void *)FUN_0087dc3d(-(uint)((int)((ulonglong)(uint)puVar3[2] * 4 >> 0x20) != 0) |
                                    (uint)((ulonglong)(uint)puVar3[2] * 4));
        (**(code **)(*piVar1 + 0x10))(iVar2,*puVar3,1);
        FUN_00727190(_Src);
        if (iVar2 != 0) {
          FUN_00891d3d(iVar2);
        }
        FUN_0082fc70(param_1,local_548);
        FID_conflict__memcpy(*(void **)(*local_54c + 0x14),_Src,puVar3[2] * 4);
        if (_Src != (void *)0x0) {
          FUN_00891d3d(_Src);
        }
      }
      local_54c = local_54c + 1;
      local_548 = local_548 + 1;
      puVar3 = puVar3 + 10;
    } while (local_548 < 0x20);
    FUN_0082fa80(param_1);
    (**(code **)(*piVar1 + 4))();
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

