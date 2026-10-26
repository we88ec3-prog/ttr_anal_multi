
void FUN_00732010(int param_1,undefined **param_2,undefined4 *param_3,undefined4 param_4)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  undefined4 *puVar4;
  char *pcVar5;
  int unaff_ESI;
  
  iVar3 = (int)param_2;
  if (*(char *)(unaff_ESI + 0x44) == '\0') {
    *(int *)(unaff_ESI + 0x48) = param_1;
    *(undefined1 *)(unaff_ESI + 0x44) = 1;
    pcVar2 = (&PTR_s_No_error_00d63c88)[param_1];
    pcVar5 = pcVar2;
    do {
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    FUN_00402a70(pcVar2,(int)pcVar5 - (int)(pcVar2 + 1));
    puVar4 = param_3;
    *(undefined4 *)(unaff_ESI + 0x70) = 0xffffffff;
    *(undefined4 *)(unaff_ESI + 0x6c) = 0xffffffff;
    if ((iVar3 != 0) && (param_3 != (undefined4 *)0x0)) {
      FUN_00730f80(iVar3,param_4);
      *(undefined4 *)(unaff_ESI + 0x6c) = *puVar4;
      *(undefined4 *)(unaff_ESI + 0x70) = puVar4[1];
    }
    param_2 = TiXmlErrorReporter::vftable;
    FUN_00731de0(&param_2,iVar3,param_3,param_4);
  }
  return;
}

