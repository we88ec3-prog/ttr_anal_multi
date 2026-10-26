
void FUN_00742e60(char *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  undefined4 in_EAX;
  char *pcVar2;
  char *in_ECX;
  int unaff_ESI;
  
  *(undefined4 *)(unaff_ESI + 8) = in_EAX;
  pcVar2 = in_ECX;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  FUN_00402a70(in_ECX,(int)pcVar2 - (int)(in_ECX + 1));
  pcVar2 = param_1;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  FUN_00402a70(param_1,(int)pcVar2 - (int)(param_1 + 1));
  *(undefined4 *)(unaff_ESI + 0x44) = param_2;
  *(undefined4 *)(unaff_ESI + 0x48) = param_3;
  *(undefined4 *)(unaff_ESI + 0x4c) = param_4;
  return;
}

