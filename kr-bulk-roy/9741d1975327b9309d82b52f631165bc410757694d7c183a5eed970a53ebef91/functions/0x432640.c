
/* WARNING: Removing unreachable block (ram,0x00432683) */
/* WARNING: Removing unreachable block (ram,0x0043268d) */

longlong FUN_00432640(undefined2 *param_1,uint param_2,int param_3)

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
        lVar5 = FUN_006ddfc0();
        if (lVar5 < 1) {
          sVar2 = (**(code **)(*in_ECX + 0xc))(*param_1);
          if (sVar2 == -1) {
            return lVar1;
          }
          param_1 = param_1 + 1;
          lVar1 = lVar1 + 1;
          bVar4 = param_2 != 0;
          param_2 = param_2 - 1;
          param_3 = param_3 + -1 + (uint)bVar4;
        }
        else {
          if (CONCAT44(param_3,param_2) < lVar5) {
            lVar5 = CONCAT44(param_3,param_2);
          }
          uVar3 = (uint)lVar5;
          FID_conflict__memcpy(*(void **)in_ECX[9],param_1,uVar3 * 2);
          param_1 = param_1 + uVar3;
          lVar1 = lVar5 + lVar1;
          bVar4 = param_2 < uVar3;
          param_2 = param_2 - uVar3;
          param_3 = (param_3 - (int)((ulonglong)lVar5 >> 0x20)) - (uint)bVar4;
          *(int *)in_ECX[0xd] = *(int *)in_ECX[0xd] - uVar3;
          *(int *)in_ECX[9] = *(int *)in_ECX[9] + uVar3 * 2;
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

