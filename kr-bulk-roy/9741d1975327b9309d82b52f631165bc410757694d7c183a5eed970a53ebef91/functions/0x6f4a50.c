
void FUN_006f4a50(char *param_1)

{
  char cVar1;
  bool bVar2;
  int *piVar3;
  int *piVar4;
  size_t sVar5;
  char *_Dst;
  void *_Src;
  uint uVar6;
  int iVar7;
  int iVar8;
  size_t _Size;
  undefined1 auStack_234 [4];
  char *pcStack_230;
  uint uStack_22c;
  int *local_228;
  undefined4 uStack_224;
  undefined4 uStack_220;
  code *pcStack_21c;
  char **ppcStack_218;
  int iStack_214;
  char local_210 [256];
  char local_110 [260];
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)auStack_234;
  iVar7 = -(int)param_1;
  do {
    cVar1 = *param_1;
    param_1[(int)(local_210 + iVar7)] = cVar1;
    param_1 = param_1 + 1;
  } while (cVar1 != '\0');
  bVar2 = true;
  piVar4 = (int *)FUN_00714770(local_210,&DAT_00bed1e0);
  if (piVar4 == (int *)0x0) goto LAB_006f4bcf;
  sVar5 = (**(code **)(*piVar4 + 0x2c))();
  _Dst = (char *)FUN_0087dc3d(sVar5 + 1);
  _Size = sVar5;
  _Src = (void *)(**(code **)(*piVar4 + 0x38))();
  FID_conflict__memcpy(_Dst,_Src,_Size);
  _Dst[sVar5] = '\0';
  uVar6 = (**(code **)(*piVar4 + 0x2c))();
  piVar3 = local_228;
  if ((((uVar6 < 3) || (*_Dst != -0x11)) || (_Dst[1] != -0x45)) || (_Dst[2] != -0x41)) {
    iStack_214 = *local_228;
    ppcStack_218 = &pcStack_230;
    uStack_224 = 0;
    uStack_220 = 0;
    pcStack_21c = FUN_006f70e0;
    pcStack_230 = _Dst;
    uStack_22c = uVar6;
    iVar7 = FUN_006fe990(iStack_214);
    if (iVar7 == 0) {
      iVar7 = *piVar3;
      pcStack_230 = (char *)(*(int *)(iVar7 + 8) + -0x10);
      iVar8 = (int)pcStack_230 - *(int *)(iVar7 + 0x20);
      goto LAB_006f4b89;
    }
LAB_006f4bb8:
    bVar2 = true;
  }
  else {
    iVar7 = FUN_006f7110(_Dst + 3,uVar6 - 3);
    if (iVar7 != 0) goto LAB_006f4bb8;
    iVar7 = *piVar3;
    pcStack_230 = (char *)(*(int *)(iVar7 + 8) + -0x10);
    iVar8 = (int)pcStack_230 - *(int *)(iVar7 + 0x20);
LAB_006f4b89:
    uStack_22c = 0xffffffff;
    iVar8 = FUN_006fe770(FUN_006f5a50,&pcStack_230,iVar8);
    if (*(uint *)(*(int *)(iVar7 + 0x14) + 8) <= *(uint *)(iVar7 + 8)) {
      *(uint *)(*(int *)(iVar7 + 0x14) + 8) = *(uint *)(iVar7 + 8);
    }
    if (iVar8 != 0) goto LAB_006f4bb8;
    bVar2 = false;
  }
  (**(code **)(*piVar4 + 4))();
  FUN_00891d3d(_Dst);
LAB_006f4bcf:
  _sprintf(local_110,"File %s",local_210);
  if (bVar2) {
    FUN_006f47a0(local_228,local_110);
  }
  __security_check_cookie(local_c ^ (uint)auStack_234);
  return;
}

