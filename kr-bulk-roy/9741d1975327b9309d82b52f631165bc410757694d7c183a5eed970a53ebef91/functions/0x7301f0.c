
/* WARNING: Removing unreachable block (ram,0x00730231) */
/* WARNING: Removing unreachable block (ram,0x0073023e) */

longlong FUN_007301f0(undefined1 *param_1,uint param_2,int param_3)

{
  longlong lVar1;
  int iVar2;
  int *in_ECX;
  uint _Size;
  bool bVar3;
  longlong lVar4;
  
  if ((-1 < param_3) && ((lVar1 = 0, 0 < param_3 || (lVar1 = 0, param_2 != 0)))) {
    while( true ) {
      do {
        lVar4 = FUN_006de690();
        if (lVar4 < 1) {
          iVar2 = (**(code **)(*in_ECX + 0x1c))();
          if (iVar2 == -1) {
            return lVar1;
          }
          *param_1 = (char)iVar2;
          lVar1 = lVar1 + 1;
          bVar3 = param_2 != 0;
          param_2 = param_2 - 1;
          param_3 = param_3 + -1 + (uint)bVar3;
          param_1 = param_1 + 1;
        }
        else {
          if (CONCAT44(param_3,param_2) < lVar4) {
            lVar4 = CONCAT44(param_3,param_2);
          }
          _Size = (uint)lVar4;
          FID_conflict__memcpy(param_1,*(void **)in_ECX[8],_Size);
          lVar1 = lVar4 + lVar1;
          bVar3 = param_2 < _Size;
          param_2 = param_2 - _Size;
          param_3 = (param_3 - (int)((ulonglong)lVar4 >> 0x20)) - (uint)bVar3;
          *(int *)in_ECX[0xc] = *(int *)in_ECX[0xc] - _Size;
          *(int *)in_ECX[8] = *(int *)in_ECX[8] + _Size;
          param_1 = param_1 + _Size;
        }
      } while (0 < param_3);
      if (param_3 < 0) break;
      if (param_2 == 0) {
        return lVar1;
      }
    }
    return lVar1;
  }
  return 0;
}

