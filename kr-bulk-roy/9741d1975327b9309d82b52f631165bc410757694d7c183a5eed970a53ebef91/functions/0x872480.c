
void FUN_00872480(char *param_1)

{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  uint *unaff_ESI;
  undefined4 *unaff_EDI;
  uint in_stack_00000018;
  
  pcVar5 = param_1;
  if (in_stack_00000018 < 0x10) {
    pcVar5 = (char *)&param_1;
  }
  *unaff_ESI = 0xffffffff;
  *unaff_EDI = 0;
  pcVar2 = pcVar5;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  uVar3 = 0;
  if (pcVar2 != pcVar5 + 1) {
    do {
      uVar4 = 0;
      do {
        if (pcVar5[uVar3] == (&DAT_00c547fc)[uVar4]) {
          *unaff_ESI = uVar3;
          *unaff_EDI = 1;
        }
        uVar4 = uVar4 + 1;
      } while (uVar4 < 0xc);
      uVar3 = uVar3 + 1;
    } while (uVar3 < (uint)((int)pcVar2 - (int)(pcVar5 + 1)));
  }
  if (0xf < in_stack_00000018) {
    FUN_0089120c(param_1);
  }
  return;
}

