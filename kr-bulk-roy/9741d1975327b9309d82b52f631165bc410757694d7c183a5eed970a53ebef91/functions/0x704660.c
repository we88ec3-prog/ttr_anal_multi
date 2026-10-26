
void FUN_00704660(undefined4 param_1,int param_2,int param_3)

{
  int *in_EAX;
  int iVar1;
  int iVar2;
  uint uVar3;
  uint local_8;
  
  iVar1 = FUN_006f53f0(3,&local_8);
  uVar3 = 0;
  if (local_8 != 0) {
    do {
      if (*(char *)(uVar3 + iVar1) == '%') {
        iVar2 = uVar3 + 1;
        uVar3 = uVar3 + 1;
        iVar2 = _isdigit((uint)*(byte *)(iVar2 + iVar1));
        if (iVar2 == 0) {
          if (in_EAX + 0x83 <= (int *)*in_EAX) {
            iVar2 = FUN_006f6af0();
            if (iVar2 != 0) {
              FUN_006f6b60();
            }
          }
          *(undefined1 *)*in_EAX = *(undefined1 *)(uVar3 + iVar1);
          *in_EAX = *in_EAX + 1;
        }
        else if (*(char *)(uVar3 + iVar1) == '0') {
          FUN_006f6c40(param_2,param_3 - param_2);
        }
        else {
          FUN_00703fd0(param_2,param_3);
          FUN_006f6cd0();
        }
      }
      else {
        if (in_EAX + 0x83 <= (int *)*in_EAX) {
          iVar2 = FUN_006f6af0();
          if (iVar2 != 0) {
            FUN_006f6b60();
          }
        }
        *(undefined1 *)*in_EAX = *(undefined1 *)(uVar3 + iVar1);
        *in_EAX = *in_EAX + 1;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < local_8);
  }
  return;
}

