
void FUN_00731750(int *param_1,int param_2)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  int *piVar4;
  int in_ECX;
  undefined4 uVar5;
  char cStack_11;
  undefined **local_10;
  int local_c;
  
  cVar1 = FUN_007312a0(param_2);
  if (cVar1 == '\0') {
    if (*(char *)(in_ECX + 0x44) == '\0') {
      *(undefined1 *)(in_ECX + 0x44) = 1;
      *(undefined4 *)(in_ECX + 0x48) = 8;
      pcVar2 = PTR_s_Error__empty_tag__00d63ca8;
      do {
        cVar1 = *pcVar2;
        pcVar2 = pcVar2 + 1;
      } while (cVar1 != '\0');
      FUN_00402a70(PTR_s_Error__empty_tag__00d63ca8,
                   (int)pcVar2 - (int)(PTR_s_Error__empty_tag__00d63ca8 + 1));
      *(undefined4 *)(in_ECX + 0x70) = 0xffffffff;
      *(undefined4 *)(in_ECX + 0x6c) = 0xffffffff;
      local_10 = TiXmlErrorReporter::vftable;
      FUN_00731de0(&local_10,0,0,0);
      return;
    }
  }
  else {
    iVar3 = *(int *)(*(int *)(*param_1 + 4) + 0xc + (int)param_1);
    while (iVar3 == 0) {
      local_c = *(int *)(param_2 + 0x10);
      do {
        iVar3 = FUN_00733b00(param_1);
        if (iVar3 == 0x3e) break;
        iVar3 = FUN_00733980(param_1);
        if (iVar3 < 1) {
          if (*(char *)(in_ECX + 0x44) == '\0') {
            *(undefined1 *)(in_ECX + 0x44) = 1;
            *(undefined4 *)(in_ECX + 0x48) = 0xe;
            pcVar2 = PTR_s_Error_null__0__or_unexpected_EOF_00d63cc0;
            do {
              cVar1 = *pcVar2;
              pcVar2 = pcVar2 + 1;
            } while (cVar1 != '\0');
            FUN_00402a70(PTR_s_Error_null__0__or_unexpected_EOF_00d63cc0,
                         (int)pcVar2 - (int)(PTR_s_Error_null__0__or_unexpected_EOF_00d63cc0 + 1));
            *(undefined4 *)(in_ECX + 0x70) = 0xffffffff;
            *(undefined4 *)(in_ECX + 0x6c) = 0xffffffff;
            local_10 = TiXmlErrorReporter::vftable;
            FUN_00731de0(&local_10,0,0,0);
          }
          break;
        }
        FUN_00429630(1,iVar3);
      } while (*(int *)(*(int *)(*param_1 + 4) + 0xc + (int)param_1) == 0);
      if (*(int *)(*(int *)(*param_1 + 4) + 0xc + (int)param_1) == 0) {
        uVar5 = 0;
        iVar3 = FUN_00403030(0);
        piVar4 = (int *)FUN_007320a0(in_ECX,iVar3 + local_c,uVar5);
        if (piVar4 == (int *)0x0) break;
        (**(code **)(*piVar4 + 0x44))(param_1,param_2);
        (**(code **)(*piVar4 + 0x14))();
        (**(code **)*piVar4)(1);
        if (cStack_11 != '\0') {
          return;
        }
      }
      iVar3 = *(int *)(*(int *)(*param_1 + 4) + 0xc + (int)param_1);
    }
    FUN_00732010(1,0,0,0);
  }
  return;
}

