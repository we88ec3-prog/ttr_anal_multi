
void FUN_007fa470(int param_1,int param_2)

{
  float fVar1;
  int iVar2;
  void *_Dst;
  uint uVar3;
  float *pfVar4;
  int *piVar5;
  int in_ECX;
  int *piVar6;
  int *piVar7;
  float *pfVar8;
  undefined2 in_FPUControlWord;
  undefined4 uStack_a0;
  int iStack_9c;
  int *piStack_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  float *pfStack_8c;
  int iStack_88;
  int iStack_84;
  undefined1 *puStack_80;
  float *pfStack_7c;
  int *piStack_78;
  float *pfVar9;
  int iVar10;
  int iStack_48;
  uint uStack_44;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_0092b83e;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if (param_1 != 0) {
    _piStack_78 = CONCAT44(0x7fa4bc,piStack_78);
    (**(code **)(**(int **)(in_ECX + 0x10) + 0x104))();
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      _piStack_78 = CONCAT44(0x7fa4d5,piStack_78);
      FUN_00798de0();
      _piStack_78 = 0xbcd2e0007fa4df;
      _atexit((_func_4879 *)&LAB_00bcd2e0);
    }
    _piStack_78 = CONCAT44(0x42,*(int **)(in_ECX + 0x10));
    pfStack_7c = (float *)0x7fa4fa;
    (**(code **)(**(int **)(in_ECX + 0x10) + 0x164))();
    uVar3 = *(int *)(in_ECX + 0x70) - *(int *)(in_ECX + 0x6c) >> 2;
    uStack_44 = 0;
    if (uVar3 != 0) {
      do {
        iVar2 = *(int *)(*(int *)(*(int *)(in_ECX + 0x6c) + uStack_44 * 4) + 0x88);
        if (iVar2 != 0) {
          iVar10 = 0;
          _piStack_78 = ZEXT48(*(int **)(in_ECX + 0x10));
          pfStack_7c = (float *)0x7fa54a;
          (**(code **)(**(int **)(in_ECX + 0x10) + 400))();
          if (*(uint *)(in_ECX + 0x4c) <= *(uint *)(in_ECX + 0x50)) {
            *(undefined4 *)(in_ECX + 0x50) = 0;
          }
          pfStack_8c = *(float **)(in_ECX + 0x48);
          pfStack_7c = (float *)((-(uint)(*(int *)(in_ECX + 0x50) != 0) & 0xfffff000) + 0x2000);
          puStack_80 = &stack0xffffffa0;
          iStack_84 = *(int *)(in_ECX + 0x54) << 4;
          iStack_88 = *(int *)(in_ECX + 0x50) << 4;
          uStack_90 = 1.1722492e-38;
          (**(code **)((int)*pfStack_8c + 0x2c))();
          iVar10 = *(int *)(*(int *)(in_ECX + 0x6c) + iVar10 * 4);
          pfVar4 = *(float **)(iVar10 + 0xe8);
          uStack_90 = *(float *)(iVar10 + 0x90) * *(float *)(in_ECX + 0x7c) *
                      *(float *)(iVar10 + 0xec);
          piStack_98 = *(int **)(in_ECX + 0x10);
          uStack_94 = 0x9a;
          iStack_9c = 0x7fa5cd;
          (**(code **)(*piStack_98 + 0xe4))();
          iStack_9c = *(int *)(*(int *)(in_ECX + 0x6c) + (int)piStack_78 * 4) + 0xa4;
          uStack_a0 = 0x100;
          (**(code **)(**(int **)(in_ECX + 0x10) + 0xb0))(*(undefined4 *)(in_ECX + 0x10));
          pfVar9 = pfVar4 + iVar2 * 0x21;
          if (pfVar4 != pfVar9) {
            pfVar4 = pfVar4 + 0x13;
            do {
              pfVar8 = pfVar4;
              if (pfVar4[-0x13] != 0.0) {
                puStack_80 = (undefined1 *)(pfVar4[1] / *pfVar4);
                *pfStack_8c = pfVar4[-0x12];
                pfStack_8c[1] = pfVar4[-0x11];
                pfStack_8c[2] = pfVar4[-0x10];
                pfStack_7c = pfVar4;
                pfVar4 = (float *)FUN_007f9f20(puStack_80);
                fVar1 = *pfVar4;
                if (NAN(fVar1) || 1.0 < fVar1 == (fVar1 == 1.0)) {
                  if (0.0 < *pfVar4) {
                    uStack_90 = (float)CONCAT22(in_FPUControlWord,(undefined2)uStack_90);
                    _piStack_78 = (ulonglong)ROUND(*pfVar4 * 255.0 + 0.5);
                    puStack_80 = (undefined1 *)piStack_78;
                  }
                  else {
                    puStack_80 = (undefined1 *)0x0;
                  }
                }
                else {
                  puStack_80 = (undefined1 *)0xff;
                }
                fVar1 = pfVar4[1];
                if (NAN(fVar1) || 1.0 < fVar1 == (fVar1 == 1.0)) {
                  piVar7 = (int *)0;
                  if (0.0 < pfVar4[1]) {
                    uStack_90 = (float)CONCAT22(in_FPUControlWord,(undefined2)uStack_90);
                    _piStack_78 = (ulonglong)ROUND(pfVar4[1] * 255.0 + 0.5);
                    piVar7 = piStack_78;
                  }
                }
                else {
                  piVar7 = (int *)0xff;
                }
                if (1.0 < pfVar4[2] == (pfVar4[2] == 1.0)) {
                  if (0.0 < pfVar4[2]) {
                    uStack_90 = (float)CONCAT22(in_FPUControlWord,(undefined2)uStack_90);
                    _piStack_78 = (ulonglong)ROUND(pfVar4[2] * 255.0 + 0.5);
                    piVar6 = piStack_78;
                  }
                  else {
                    piVar6 = (int *)0;
                  }
                }
                else {
                  piVar6 = (int *)0xff;
                }
                if (1.0 < pfVar4[3] == (pfVar4[3] == 1.0)) {
                  if (0.0 < pfVar4[3]) {
                    uStack_90 = (float)CONCAT22(in_FPUControlWord,(undefined2)uStack_90);
                    _piStack_78 = (ulonglong)ROUND(pfVar4[3] * 255.0 + 0.5);
                    piVar5 = piStack_78;
                  }
                  else {
                    piVar5 = (int *)0;
                  }
                }
                else {
                  piVar5 = (int *)0xff;
                }
                pfStack_8c[3] =
                     (float)((((int)piVar5 << 8 | (uint)puStack_80) << 8 | (uint)piVar7) << 8 |
                            (uint)piVar6);
                pfStack_8c = pfStack_8c + 4;
                iStack_88 = iStack_88 + 1;
                if (iStack_88 == *(int *)(in_ECX + 0x54)) {
                  (**(code **)(**(int **)(in_ECX + 0x48) + 0x30))(*(int **)(in_ECX + 0x48));
                  (**(code **)(**(int **)(in_ECX + 0x10) + 0x144))
                            (*(int **)(in_ECX + 0x10),1,*(undefined4 *)(in_ECX + 0x50),
                             *(undefined4 *)(in_ECX + 0x54));
                  *(int *)(in_ECX + 0x50) = *(int *)(in_ECX + 0x50) + *(int *)(in_ECX + 0x54);
                  if (*(uint *)(in_ECX + 0x4c) <= *(uint *)(in_ECX + 0x50)) {
                    *(undefined4 *)(in_ECX + 0x50) = 0;
                  }
                  (**(code **)(**(int **)(in_ECX + 0x48) + 0x2c))
                            (*(int **)(in_ECX + 0x48),*(int *)(in_ECX + 0x50) << 4,
                             *(int *)(in_ECX + 0x54) << 4,&uStack_a0,
                             (-(uint)(*(int *)(in_ECX + 0x50) != 0) & 0xfffff000) + 0x2000);
                  iStack_88 = 0;
                  pfVar8 = pfStack_7c;
                }
              }
              pfVar4 = pfVar8 + 0x21;
              pfStack_7c = pfVar4;
            } while (pfVar8 + 0xe != pfVar9);
          }
          (**(code **)(**(int **)(in_ECX + 0x48) + 0x30))(*(int **)(in_ECX + 0x48));
          if (iStack_48 != 0) {
            _piStack_78 = CONCAT44(*(int **)(in_ECX + 0x10),0x7fa89b);
            (**(code **)(**(int **)(in_ECX + 0x10) + 0x144))();
          }
          *(int *)(in_ECX + 0x50) = *(int *)(in_ECX + 0x50) + *(int *)(in_ECX + 0x54);
        }
        uStack_44 = uStack_44 + 1;
      } while (uStack_44 < uVar3);
    }
  }
  if (param_2 != 0) {
    _Dst = *(void **)(in_ECX + 0x6c);
    if (_Dst != *(void **)(in_ECX + 0x70)) {
      _piStack_78 = CONCAT44(0x7fa8dd,piStack_78);
      FID_conflict__memcpy(_Dst,*(void **)(in_ECX + 0x70),0);
      *(void **)(in_ECX + 0x70) = _Dst;
    }
  }
  ExceptionList = local_14;
  return;
}

