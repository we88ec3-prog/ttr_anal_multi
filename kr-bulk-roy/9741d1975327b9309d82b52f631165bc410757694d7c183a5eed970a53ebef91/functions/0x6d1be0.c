
int FUN_006d1be0(int param_1,int *param_2)

{
  void *_Src;
  size_t sVar1;
  void *_Dst;
  void *pvVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  uint local_c;
  
  iVar4 = (int)param_2 - param_1;
  local_c = 0;
  piVar5 = (int *)(param_1 + 4);
  do {
    if (piVar5 + -1 != param_2) {
      pvVar2 = (void *)*param_2;
      uVar3 = *(int *)(iVar4 + (int)piVar5) - (int)pvVar2 >> 2;
      if (uVar3 == 0) {
        pvVar2 = (void *)piVar5[-1];
        if (pvVar2 != (void *)*piVar5) {
          FID_conflict__memcpy(pvVar2,(void *)*piVar5,0);
          *piVar5 = (int)pvVar2;
        }
      }
      else {
        _Dst = (void *)piVar5[-1];
        uVar6 = *piVar5 - (int)_Dst >> 2;
        if (uVar6 < uVar3) {
          if ((uint)(piVar5[1] - (int)_Dst >> 2) < uVar3) {
            if (_Dst != (void *)0x0) {
              FUN_0089120c(_Dst);
            }
            uVar3 = *(int *)(iVar4 + (int)piVar5) - *param_2 >> 2;
            piVar5[-1] = 0;
            *piVar5 = 0;
            piVar5[1] = 0;
            if (uVar3 == 0) goto LAB_006d1d37;
            if (0x3fffffff < uVar3) {
                    /* WARNING: Subroutine does not return */
              FUN_0087db30("vector<T> too long");
            }
            pvVar2 = (void *)FUN_007d01e0();
            piVar5[1] = (int)((int)pvVar2 + uVar3 * 4);
            piVar5[-1] = (int)pvVar2;
            *piVar5 = (int)pvVar2;
            sVar1 = (*(int *)(iVar4 + (int)piVar5) - *param_2 >> 2) * 4;
            pvVar2 = FID_conflict__memcpy(pvVar2,(void *)*param_2,sVar1);
            pvVar2 = (void *)((int)pvVar2 + sVar1);
          }
          else {
            _Src = (void *)((int)pvVar2 + uVar6 * 4);
            FID_conflict__memcpy(_Dst,pvVar2,((int)_Src - (int)pvVar2 >> 2) * 4);
            sVar1 = (*(int *)(iVar4 + (int)piVar5) - (int)_Src >> 2) * 4;
            pvVar2 = FID_conflict__memcpy((void *)*piVar5,_Src,sVar1);
            pvVar2 = (void *)((int)pvVar2 + sVar1);
          }
        }
        else {
          FID_conflict__memcpy(_Dst,pvVar2,(*(int *)(iVar4 + (int)piVar5) - (int)pvVar2 >> 2) * 4);
          pvVar2 = (void *)(piVar5[-1] + (*(int *)(iVar4 + (int)piVar5) - *param_2 >> 2) * 4);
        }
        *piVar5 = (int)pvVar2;
      }
    }
LAB_006d1d37:
    local_c = local_c + 1;
    param_2 = param_2 + 4;
    piVar5 = piVar5 + 4;
    if (0x27 < local_c) {
      return param_1;
    }
  } while( true );
}

