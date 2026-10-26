
void FUN_008e2300(void *param_1)

{
  char cVar1;
  int in_EAX;
  
  if ((*(int *)(in_EAX + 0x14) == *(int *)(in_EAX + 0xc)) && (cVar1 = FUN_008e2230(), cVar1 == '\0')
     ) {
    return;
  }
  FID_conflict__memcpy
            ((void *)(*(int *)(in_EAX + 0x14) * *(size_t *)(in_EAX + 8) + *(int *)(in_EAX + 0x1c)),
             param_1,*(size_t *)(in_EAX + 8));
  *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
  return;
}

