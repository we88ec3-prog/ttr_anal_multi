
void FUN_0071c710(double param_1,undefined4 *param_2,int *param_3)

{
  char *pcVar1;
  char *pcVar2;
  char *unaff_ESI;
  int local_c;
  int local_8;
  
  __ecvt_s(unaff_ESI,0x40,param_1,0x10,&local_8,&local_c);
  pcVar1 = unaff_ESI;
  do {
    pcVar2 = pcVar1;
    pcVar1 = pcVar2 + 1;
  } while (*pcVar2 != '\0');
  for (; (unaff_ESI != pcVar2 && (pcVar2[-1] == '0')); pcVar2 = pcVar2 + -1) {
  }
  *pcVar2 = '\0';
  *param_2 = unaff_ESI;
  *param_3 = local_8;
  return;
}

