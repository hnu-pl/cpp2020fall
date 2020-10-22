#include <iostream>
using namespace std;

struct Node { string value; Node* next; };
struct BasketL { Node* items; }; // 리스트로 만든 장바구니

// HW3: printL과 clearL을 반복문이 아닌 재귀함수를 이용해 구현하라
void printL(const BasketL& b); // (1) printList라는 재귀함수를 이용해 작성하라
void clearL(BasketL& b); // (2) clearList라는 재귀함수를 이용해 작성하라

int main() {
	BasketL b3 = { nullptr }; // b3.items라는 리스트 노드에 대한 포인터를 nullptr로 초기화
	b3.items = new Node{ "사과", b3.items };
	b3.items = new Node{ "배", b3.items };
	b3.items = new Node{ "김밥", b3.items };
	b3.items = new Node{ "소고기", b3.items };
	b3.items = new Node{ "삼겹살", b3.items };
	b3.items = new Node{ "상추", b3.items };
	b3.items = new Node{ "쌈장", b3.items };
	b3.items = new Node{ "아이스크림", b3.items };
	printL(b3);
	clearL(b3); // 동적으로 할당된 메모리를 모두 해제하여 바구니를 비우기
	printL(b3);
	return 0;
}

void printList(const Node* l) {
	// 적절히 재귀함수 작성 (재귀함수이므로 반복문 사용 금지)
}

void printL(const BasketL& b) {
	cout <<"BasketL:";

	for (Node* l = b.items; l; l = l->next)
		cout <<" " <<l->value;
	
	cout <<endl;
}

void clearList(Node* l) {
	// 적절히 재귀함수 작성 (재귀함수이므로 반복문 사용 금지)
}

void clearL(BasketL& b) {
	// l을 먼저 delete해버리면 next를 따라가지 못하니까 next를 먼저 임시로 저장해 놓고 l을 delete
	Node* tmp_next;
	for (Node* l = b.items; l; l = tmp_next) {
		tmp_next = l->next;
		delete l;
	}
	
	b.items = nullptr; // 최종적으로는 빈 장바구니이므로 널포인터로 다시 설정
}
