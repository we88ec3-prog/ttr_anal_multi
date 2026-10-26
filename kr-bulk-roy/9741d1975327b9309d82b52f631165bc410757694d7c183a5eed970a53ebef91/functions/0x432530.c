
/* WARNING: Removing unreachable block (ram,0x00432573) */
/* WARNING: Removing unreachable block (ram,0x0043257d) */

longlong FUN_00432530(short *param_1,uint param_2,int param_3)

{
  longlong lVar1;
  short sVar2;
  int *in_ECX;
  uint uVar3;
  bool bVar4;
  longlong lVar5;
  
  if ((-1 < param_3) && ((lVar1 = 0, 0 < param_3 || (lVar1 = 0, param_2 != 0)))) {
    while( true ) {
      do {
        lVar5 = FUN_006de690();
        if (lVar5 < 1) {
          sVar2 = (**(code **)(*in_ECX + 0x1c))();
          if (sVar2 == -1) {
            return lVar1;
          }
          *param_1 = sVar2;
          lVar1 = lVar1 + 1;
          bVar4 = param_2 != 0;
          param_2 = param_2 - 1;
          param_3 = param_3 + -1 + (uint)bVar4;
          param_1 = param_1 + 1;
        }
        else {
          if (CONCAT44(param_3,param_2) < lVar5) {
            lVar5 = CONCAT44(param_3,param_2);
          }
          uVar3 = (uint)lVar5;
          FID_conflict__memcpy(param_1,*(void **)in_ECX[8],uVar3 * 2);
          lVar1 = lVar5 + lVar1;
          bVar4 = param_2 < uVar3;
          param_2 = param_2 - uVar3;
          param_3 = (param_3 - (int)((ulonglong)lVar5 >> 0x20)) - (uint)bVar4;
          *(int *)in_ECX[0xc] = *(int *)in_ECX[0xc] - uVar3;
          *(int *)in_ECX[8] = *(int *)in_ECX[8] + uVar3 * 2;
          param_1 = param_1 + uVar3;
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

