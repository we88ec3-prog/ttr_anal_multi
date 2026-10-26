
/* WARNING: Removing unreachable block (ram,0x008be8c2) */

int FUN_008be830(char *param_1,undefined4 param_2)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  void *_Dst;
  int iVar5;
  undefined4 *puVar6;
  int unaff_EDI;
  int local_8;
  
  uVar2 = *(undefined4 *)(unaff_EDI + 0x44088);
  local_8 = 0;
  iVar3 = FUN_008bdf60(unaff_EDI + 0x44094);
  iVar5 = 0;
  if (iVar3 == 0) {
    iVar3 = FUN_008bc7d0(uVar2,0x10,*(int *)(unaff_EDI + 0x44090),*(int *)(unaff_EDI + 0x44090) + 1,
                         *(undefined4 *)(unaff_EDI + 0x4408c),&local_8);
    *(int *)(unaff_EDI + 0x4408c) = iVar3;
    iVar5 = local_8;
    if (local_8 == 0) {
      puVar6 = (undefined4 *)(*(int *)(unaff_EDI + 0x44090) * 0x10 + iVar3);
      *puVar6 = 0;
      puVar6[1] = 0;
      puVar6[2] = 0;
      puVar6[3] = 0;
      pcVar4 = param_1;
      do {
        cVar1 = *pcVar4;
        pcVar4 = pcVar4 + 1;
      } while (cVar1 != '\0');
      _Dst = (void *)FUN_008bc7d0(uVar2,1,0,pcVar4 + (1 - (int)(param_1 + 1)),0,&local_8);
      *puVar6 = _Dst;
      iVar5 = local_8;
      if (local_8 == 0) {
        FID_conflict__memcpy(_Dst,param_1,(size_t)(pcVar4 + (1 - (int)(param_1 + 1))));
        puVar6[1] = param_2;
        puVar6[2] = 0;
        iVar5 = FUN_008bded0(*(int *)(unaff_EDI + 0x44090) + 0x53,uVar2);
        if (iVar5 == 0) {
          *(int *)(unaff_EDI + 0x44090) = *(int *)(unaff_EDI + 0x44090) + 1;
        }
      }
    }
  }
  return iVar5;
}

