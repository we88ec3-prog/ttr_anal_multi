
void FUN_007f1770(void)

{
  char *pcVar1;
  char cVar2;
  int iVar3;
  void *_Dst;
  undefined1 uVar4;
  int *piVar5;
  uint uVar6;
  char *pcVar7;
  int *piVar8;
  undefined4 *puVar9;
  int in_ECX;
  int *piVar10;
  undefined4 uVar11;
  undefined1 auStack_174 [4];
  char ***local_170;
  int local_16c;
  undefined1 auStack_168 [4];
  int *piStack_164;
  undefined4 uStack_160;
  int local_158;
  int local_154;
  undefined **appuStack_150 [3];
  char ***local_144 [4];
  undefined4 local_134;
  uint local_130;
  char local_128 [268];
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_009376f6;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_174;
  uVar6 = DAT_00d61f20 ^ (uint)&stack0xfffffe80;
  ExceptionList = &local_14;
  local_16c = in_ECX;
  if (*(int *)(in_ECX + 0x88) == 0) {
    pcVar1 = (char *)(in_ECX + 0x30);
    pcVar7 = pcVar1;
    do {
      cVar2 = *pcVar7;
      pcVar7 = pcVar7 + 1;
    } while (cVar2 != '\0');
    if (pcVar7 != (char *)(in_ECX + 0x31)) {
      local_144[0] = (char ***)((uint)local_144[0] & 0xffffff00);
      local_130 = 0xf;
      local_134 = 0;
      FUN_00402a70("Effect/Object/",0xe);
      local_c = 0;
      pcVar7 = pcVar1;
      do {
        cVar2 = *pcVar7;
        pcVar7 = pcVar7 + 1;
      } while (cVar2 != '\0');
      FUN_00401fc0(pcVar1,(int)pcVar7 - (in_ECX + 0x31));
      uVar11 = 0;
      FUN_00798d70(0);
      uVar11 = FUN_007d0920(uVar11);
      local_c = 0xffffffff;
      *(undefined4 *)(in_ECX + 0x88) = uVar11;
      if (0xf < local_130) {
        FUN_0089120c(local_144[0]);
      }
    }
  }
  iVar3 = *(int *)(in_ECX + 0x88);
  if (iVar3 == 0) {
    _sprintf(local_128,"%s - Couldn\'t Open File!!! - CEffectElement::OnCreateDevice()",
             in_ECX + 0x30,uVar6);
    MessageBoxA((HWND)0x0,local_128,"Error",0);
  }
  else {
    if ((*(int *)(iVar3 + 0xdc) - *(int *)(iVar3 + 0xd8) & 0xfffffffcU) != 0) {
      local_170 = (char ***)FUN_00891268(0xe8);
      local_c = 1;
      if ((char ****)local_170 == (char ****)0x0) {
        piVar8 = (int *)0x0;
      }
      else {
        piVar8 = (int *)FUN_0077ebb0();
      }
      local_c = 0xffffffff;
      (**(code **)(*piVar8 + 0x40))(*(undefined4 *)(in_ECX + 0x88));
      *(int **)(in_ECX + 0x88) = piVar8;
    }
    local_158 = 0;
    local_154 = 0;
    FUN_007c5f40(*(undefined4 *)(in_ECX + 0x88),&local_158);
    uVar6 = local_154 - local_158 >> 0x1f;
    local_170 = (char ***)(float)(int)((local_154 - local_158 ^ uVar6) - uVar6);
    *(char ****)(in_ECX + 0x70) = local_170;
    if ((float)local_170 <= 0.0) {
      *(undefined4 *)(in_ECX + 0x70) = 0x4b7fffff;
    }
    uStack_160 = 0;
    piStack_164 = (int *)FUN_00891268(0x2c);
    if (piStack_164 == (int *)0x0) {
      local_170 = (char ***)0x0;
      std::exception::exception((exception *)appuStack_150,(char **)&local_170);
      appuStack_150[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(appuStack_150,&DAT_00c857a8);
    }
    *piStack_164 = (int)piStack_164;
    piStack_164[1] = (int)piStack_164;
    piStack_164[2] = (int)piStack_164;
    *(undefined1 *)(piStack_164 + 10) = 1;
    *(undefined1 *)((int)piStack_164 + 0x29) = 1;
    local_c._1_3_ = 0;
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_c._0_1_ = 3;
      local_c._1_3_ = 0;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
    }
    local_c._0_1_ = 2;
    FUN_007c6ce0(DAT_00fb76a8,*(undefined4 *)(in_ECX + 0x88),auStack_168);
    local_130 = 0xf;
    local_134 = 0;
    local_144[0] = (char ***)((uint)local_144[0] & 0xffffff00);
    local_c._0_1_ = 4;
    uVar4 = (undefined1)local_c;
    local_c._0_1_ = 4;
    piVar8 = (int *)*piStack_164;
    if (piVar8 != piStack_164) {
      do {
        FUN_00402a70("Effect/Texture/",0xf);
        piVar10 = piVar8 + 3;
        FUN_00401ed0(piVar10,0,0xffffffff);
        if (local_130 < 0x10) {
          local_170 = (char ***)local_144;
        }
        else {
          local_170 = local_144[0];
        }
        if (0xf < (uint)piVar8[8]) {
          piVar10 = (int *)*piVar10;
        }
        if ((DAT_00fe1ac0 & 1) == 0) {
          DAT_00fe1ac0 = DAT_00fe1ac0 | 1;
          local_c._0_1_ = 5;
          FUN_007bb970();
          _atexit((_func_4879 *)&LAB_00bceac0);
          local_c._0_1_ = 4;
        }
        EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fe1b08);
        (*DAT_00fe1ae0)(piVar10,local_170);
        SetEvent(DAT_00fe1b2c);
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fe1b08);
        if (*(char *)((int)piVar8 + 0x29) == '\0') {
          piVar10 = (int *)piVar8[2];
          if (*(char *)((int)piVar10 + 0x29) == '\0') {
            cVar2 = *(char *)(*piVar10 + 0x29);
            piVar8 = piVar10;
            piVar10 = (int *)*piVar10;
            while (cVar2 == '\0') {
              cVar2 = *(char *)(*piVar10 + 0x29);
              piVar8 = piVar10;
              piVar10 = (int *)*piVar10;
            }
          }
          else {
            cVar2 = *(char *)(piVar8[1] + 0x29);
            piVar5 = (int *)piVar8[1];
            piVar10 = piVar8;
            while ((piVar8 = piVar5, cVar2 == '\0' && (piVar10 == (int *)piVar8[2]))) {
              cVar2 = *(char *)(piVar8[1] + 0x29);
              piVar5 = (int *)piVar8[1];
              piVar10 = piVar8;
            }
          }
        }
        uVar4 = (undefined1)local_c;
      } while (piVar8 != piStack_164);
    }
    local_c._0_1_ = uVar4;
    if ((DAT_00fe333c & 1) == 0) {
      DAT_00fe333c = DAT_00fe333c | 1;
      local_c._0_1_ = 6;
      FUN_007fca90();
      _atexit(FUN_00bd0b20);
      local_c._0_1_ = 4;
    }
    puVar9 = (undefined4 *)FUN_007fced0();
    *(undefined4 **)(in_ECX + 0xac) = puVar9;
    *(undefined4 *)(in_ECX + 0xb0) = *puVar9;
    FUN_007f1eb0(in_ECX);
    _Dst = *(void **)(in_ECX + 0x9c);
    piVar8 = (int *)(in_ECX + 0x9c);
    if (_Dst != *(void **)(in_ECX + 0xa0)) {
      FID_conflict__memcpy(_Dst,*(void **)(in_ECX + 0xa0),0);
      *(void **)(in_ECX + 0xa0) = _Dst;
      in_ECX = local_16c;
    }
    FUN_007cbb00(*(undefined4 *)(in_ECX + 0x88),piVar8);
    piVar8 = (int *)*piVar8;
    if (piVar8 != *(int **)(in_ECX + 0xa0)) {
      do {
        iVar3 = *piVar8;
        FUN_0084b1d0();
        piVar8 = piVar8 + 1;
        *(undefined4 *)(iVar3 + 0xa8) = 1;
      } while (piVar8 != *(int **)(in_ECX + 0xa0));
    }
    *(undefined4 *)(in_ECX + 4) = 1;
    if (0xf < local_130) {
      FUN_0089120c(local_144[0]);
    }
    local_130 = 0xf;
    local_134 = 0;
    local_144[0] = (char ***)((uint)local_144[0] & 0xffffff00);
    local_c = 7;
    FUN_004ad180(*piStack_164,piStack_164);
    FUN_0089120c(piStack_164);
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_174);
  return;
}

