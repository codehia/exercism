namespace hellmath {

enum class AccountStatus { troll, guest, user, mod };

enum class Action { read, write, remove };

bool display_post(AccountStatus poster, AccountStatus viewer) {
    if (poster == AccountStatus::troll) {
        return viewer == AccountStatus::troll;
    }
    return true;
}

bool permission_check(Action action, AccountStatus status) {
    if (status == AccountStatus::mod) {
        return true;
    } else if (status == AccountStatus::guest) {
        return action == Action::read;
    } else {
        return action == Action::read || action == Action::write;
    }
}

bool valid_player_combination(AccountStatus first_player,
                              AccountStatus second_player) {
    if (first_player == AccountStatus::guest ||
        second_player == AccountStatus::guest) {
        return false;
    } else if (first_player == AccountStatus::troll ||
               second_player == AccountStatus::troll) {
        return first_player == second_player;
    } else {
        return true;
    }
}

bool has_priority(AccountStatus first_player, AccountStatus second_player) {
    // mod -> user -> guest -> troll
    if (first_player == AccountStatus::mod) {
        return second_player != AccountStatus::mod;
    } else if (first_player == AccountStatus::troll) {
        return false;
    } else if (first_player == AccountStatus::guest) {
        return second_player == AccountStatus::troll;
    } else {
        return second_player == AccountStatus::guest ||
               second_player == AccountStatus::troll;
    }
}
}  // namespace hellmath
